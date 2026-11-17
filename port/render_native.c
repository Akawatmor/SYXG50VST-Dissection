#include "syxg_core.h"
#include <stdio.h>
#include <stdlib.h>

static int load_file(const char *path, uint8_t *buffer, uint32_t capacity) {
    FILE *file = fopen(path, "rb");
    if (!file) return 0;
    size_t length = fread(buffer, 1, capacity, file);
    int extra = fgetc(file);
    fclose(file);
    return length == capacity && extra == EOF;
}

int main(int argc, char **argv) {
    if (argc < 4 || argc > 8) {
        fprintf(stderr, "Usage: render_native bank.tbl wave.tbl output.f32 [note=60] [velocity=100] [program=0] [rate=44100]\n");
        return 2;
    }
    uint32_t note = argc > 4 ? (uint32_t)atoi(argv[4]) : 60;
    uint32_t velocity = argc > 5 ? (uint32_t)atoi(argv[5]) : 100;
    uint32_t program = argc > 6 ? (uint32_t)atoi(argv[6]) : 0;
    uint32_t rate = argc > 7 ? (uint32_t)atoi(argv[7]) : 44100;
    if (!load_file(argv[1], sxg_bank_buffer(), sxg_bank_capacity()) ||
        !load_file(argv[2], sxg_wave_buffer(), sxg_wave_capacity())) {
        fprintf(stderr, "Input file could not be read at its expected size\n");
        return 3;
    }
    int error = sxg_init(sxg_bank_capacity(), sxg_wave_capacity(), rate);
    if (!error) error = sxg_midi(0xC0, program, 0);
    if (error) { fprintf(stderr, "Initialization failed (%d)\n", error); return 4; }
    FILE *file = fopen(argv[3], "wb");
    if (!file) return 5;
    uint32_t note_on = (rate / 4 / 128) * 128;
    uint32_t note_off = (rate * 5 / 4 / 128) * 128;
    uint32_t total = rate * 4;
    for (uint32_t position = 0; position < total; position += 128) {
        uint32_t frames = total - position < 128 ? total - position : 128;
        if (position == note_on) error = sxg_midi(0x90, note, velocity);
        if (position == note_off) error = sxg_midi(0x80, note, 0);
        if (!error) error = sxg_render(frames);
        if (error || fwrite(sxg_output_buffer(), sizeof(float) * 2, frames, file) != frames) {
            fprintf(stderr, "Render failed at frame %u (%d)\n", position, error);
            fclose(file);
            return 6;
        }
    }
    if (fclose(file) != 0) return 7;
    printf("layers=%u rate=%u frames=%u\n", sxg_layer_count(), rate, total);
    for (uint32_t index = 0; index < sxg_layer_count(); ++index) {
        printf("layer=%u record=0x%X start=0x%X base=0x%X end=0x%X bytes=%u root=%u flags=0x%X\n",
               index, sxg_layer_info(index, 0), sxg_layer_info(index, 1), sxg_layer_info(index, 2),
               sxg_layer_info(index, 3), sxg_layer_info(index, 4), sxg_layer_info(index, 5), sxg_layer_info(index, 6));
    }
    return 0;
}
