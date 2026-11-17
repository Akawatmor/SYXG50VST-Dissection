#include "syxg_core.h"

#define BANK_CAPACITY 145014u
#define WAVE_CAPACITY 4299476u
#define OUTPUT_FRAMES 4096u
#define MAX_LAYERS 2u
#define MAX_VOICES 128u
#define MIDI_CHANNELS 16u

typedef struct {
    uint32_t offset;
    uint32_t length;
} Segment;

typedef struct {
    uint32_t record_offset;
    uint32_t sample_start;
    uint32_t sample_base;
    uint32_t sample_end;
    uint32_t bytes_per_sample;
    uint32_t sample_count;
    uint32_t loop_start;
    uint32_t note;
    uint32_t root_key;
    uint32_t flags;
    double position;
    double step;
    uint32_t step_q15;
    double gain;
    double release_gain;
    uint32_t releasing;
    uint32_t active;
    uint32_t channel;
    uint32_t key_down;
    uint32_t age;
    uint32_t exclusive_group;
    uint32_t receive_note_off;
    uint32_t looping;
    uint32_t loop_fraction;
    double base_step;
    double pan;
    double filter_state;
    double filter_state2;
    double attack_gain;
    double decay_multiplier;
} Layer;

typedef struct {
    uint32_t program, bank_msb, bank_lsb;
    uint32_t volume, expression, pan, sustain, modulation;
    uint32_t reverb, chorus, cutoff, resonance;
    uint32_t pitch_bend, bend_semitones, bend_cents;
    uint32_t rpn_msb, rpn_lsb, drum;
    int32_t transpose;
} Channel;

static uint8_t bank_data[BANK_CAPACITY];
static uint8_t wave_data[WAVE_CAPACITY];
static float output[OUTPUT_FRAMES * 2u];
static int32_t oscillator_output[OUTPUT_FRAMES];
static int32_t oscillator_position;
static uint32_t oscillator_fraction;
static Segment segments[17];
static Layer layers[MAX_VOICES];
static Channel channels[MIDI_CHANNELS];
static uint32_t selected_indices[MAX_LAYERS];
static uint32_t output_rate;
static uint32_t loaded_wave_size;
static uint32_t initialized;
static uint32_t selected_layers;
static uint32_t voice_age;
static float master_volume = 0.8f;
static uint32_t effects_enabled = 1;
static uint32_t reset_mode = 1;
static uint8_t sysex_buffer[1024];
static void reset_effects(void);

static uint32_t read_le16(const uint8_t *data) {
    return (uint32_t)data[0] | (uint32_t)data[1] << 8;
}

static uint32_t read_le32(const uint8_t *data) {
    return (uint32_t)data[0] | (uint32_t)data[1] << 8 |
           (uint32_t)data[2] << 16 | (uint32_t)data[3] << 24;
}

static uint32_t read_be24(const uint8_t *data) {
    return (uint32_t)data[0] << 16 | (uint32_t)data[1] << 8 | data[2];
}

/* Explicit arithmetic gives native and freestanding Wasm the same pitch calculation. */
static double power_of_two(double exponent) {
    int whole = (int)exponent;
    double fraction = exponent - whole;
    double term = 1.0;
    double result = 1.0;
    double argument = fraction * 0.69314718055994530942;
    for (int index = 1; index <= 16; ++index) {
        term *= argument / index;
        result += term;
    }
    while (whole > 0) {
        result *= 2.0;
        --whole;
    }
    while (whole < 0) {
        result *= 0.5;
        ++whole;
    }
    return result;
}

uint8_t *sxg_bank_buffer(void) { return bank_data; }
uint8_t *sxg_wave_buffer(void) { return wave_data; }
uint32_t sxg_bank_capacity(void) { return BANK_CAPACITY; }
uint32_t sxg_wave_capacity(void) { return WAVE_CAPACITY; }
float *sxg_output_buffer(void) { return output; }
uint32_t sxg_layer_count(void) { return selected_layers; }
int32_t *sxg_oscillator_output(void) { return oscillator_output; }
int32_t sxg_oscillator_position(void) { return oscillator_position; }
uint32_t sxg_oscillator_fraction(void) { return oscillator_fraction; }

/* Recovered from legacy RVA 0x19580 and 0x19540. */
double sxg_envelope_gain(int32_t value) {
    if (value < 0) return 1.0;
    if (value > 0xFFFFE) return 0.0;
    uint32_t denominator_scale = 1u << ((uint32_t)value >> 16);
    return (double)(((uint32_t)~value & 0xFFFFu) | 0x10000u) /
           ((double)denominator_scale * 131071.0);
}

int sxg_envelope_advance(int32_t *value, int32_t target, int32_t rate) {
    if (*value == target) return 1;
    if (*value > target) {
        *value -= rate;
        if (*value < target) { *value = target; return 1; }
    } else {
        *value += rate;
        if (*value > target) { *value = target; return 1; }
    }
    return 0;
}

/* Scalar equivalent of the supplied legacy MMX kernel at RVA 0x1ABB0. */
static int32_t interpolate8(uint32_t address, uint32_t fraction) {
    int32_t first = ((int32_t)(wave_data[address] ^ 0x5C) - 128) * 256;
    int32_t second = ((int32_t)(wave_data[address + 1] ^ 0x5C) - 128) * 256;
    return first * (int32_t)(32767 - fraction) + second * (int32_t)fraction;
}

int sxg_probe_oscillator8(uint32_t base, int32_t loop_end, uint32_t loop_fraction,
                         int32_t position, uint32_t fraction, uint32_t step, uint32_t frames) {
    if (!initialized) return SXG_NOT_INITIALIZED;
    if (!frames || frames > OUTPUT_FRAMES || loop_end <= 0 || fraction >= 32768 ||
        loop_fraction >= 32768 || step > 32768u * 256u ||
        base >= loaded_wave_size || (uint32_t)loop_end >= loaded_wave_size - base ||
        position < -(int32_t)base || position >= loop_end) return SXG_BAD_ARGUMENT;
    for (uint32_t frame = 0; frame < frames; ++frame) {
        oscillator_output[frame] = interpolate8((uint32_t)((int64_t)base + position), fraction);
        fraction += step;
        position += (int32_t)(fraction >> 15);
        fraction &= 32767;
        while (position >= loop_end) {
            fraction += loop_fraction;
            position += (int32_t)(fraction >> 15) - loop_end;
            fraction &= 32767;
        }
    }
    oscillator_position = position;
    oscillator_fraction = fraction;
    return SXG_OK;
}

void sxg_reset(void) {
    for (uint32_t index = 0; index < MAX_VOICES; ++index) {
        layers[index].active = 0;
    }
    for (uint32_t index = 0; index < MIDI_CHANNELS; ++index) {
        Channel defaults = {0};
        defaults.volume = 100;
        defaults.expression = 127;
        defaults.pan = 64;
        defaults.pitch_bend = 8192;
        defaults.bend_semitones = 2;
        defaults.rpn_msb = 127;
        defaults.rpn_lsb = 127;
        defaults.reverb = 40;
        defaults.cutoff = 64;
        defaults.resonance = 64;
        defaults.drum = index == 9;
        channels[index] = defaults;
    }
    master_volume = 0.8f;
    selected_layers = 0;
    voice_age = 0;
    reset_effects();
}

int sxg_init(uint32_t bank_size, uint32_t wave_size, uint32_t sample_rate) {
    initialized = 0;
    sxg_reset();
    if (bank_size != BANK_CAPACITY || wave_size != WAVE_CAPACITY ||
        (sample_rate < 22050 || sample_rate > 192000)) {
        return SXG_BAD_ARGUMENT;
    }
    const uint8_t signature[] = {'M', 'U', '5', '0', ' ', '4', 'M', 'B'};
    for (uint32_t index = 0; index < sizeof(signature); ++index) {
        if (bank_data[index] != signature[index]) return SXG_BAD_BANK;
    }
    uint32_t cursor = 100;
    for (uint32_t index = 0; index < 17; ++index) {
        uint32_t length = read_le32(bank_data + 32 + index * 4);
        if (length > bank_size - cursor) return SXG_BAD_BANK;
        segments[index].offset = cursor;
        segments[index].length = length;
        cursor += length;
    }
    if (cursor != bank_size || segments[8].length < 128 ||
        segments[9].length < 128 || segments[10].length < 128 ||
        segments[12].length < 256 || segments[15].length < 2) return SXG_BAD_BANK;

    /* Recovered from legacy RVA 0x32B80. The input wave buffer is decoded in place. */
    for (uint32_t index = 0; index < wave_size; ++index) {
        uint8_t alternating = (index & 1u) ? 0xA2 : 0x5D;
        uint8_t value = wave_data[index] ^ alternating ^ (uint8_t)index;
        wave_data[index] = (uint8_t)((value << 4) | (value >> 4)) ^ 0x5C;
    }
    loaded_wave_size = wave_size;
    output_rate = sample_rate;
    initialized = 1;
    return SXG_OK;
}

#include "syxg_synth.inc"
