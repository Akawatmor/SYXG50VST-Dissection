#ifndef SYXG_CORE_H
#define SYXG_CORE_H

#include <stdint.h>

enum {
    SXG_OK = 0,
    SXG_BAD_ARGUMENT = 1,
    SXG_BAD_BANK = 2,
    SXG_UNSUPPORTED = 3,
    SXG_BAD_SAMPLE = 4,
    SXG_NOT_INITIALIZED = 5
};

/* Multi-channel sampler with recovered oscillator primitives. */
uint8_t *sxg_bank_buffer(void);
uint8_t *sxg_wave_buffer(void);
uint32_t sxg_bank_capacity(void);
uint32_t sxg_wave_capacity(void);
int sxg_init(uint32_t bank_size, uint32_t wave_size, uint32_t sample_rate);
int sxg_midi(uint32_t status, uint32_t data1, uint32_t data2);
int sxg_render(uint32_t frames);
float *sxg_output_buffer(void);
void sxg_reset(void);
uint32_t sxg_layer_count(void);
uint32_t sxg_layer_info(uint32_t layer, uint32_t field);
int sxg_probe_oscillator8(uint32_t base, int32_t loop_end, uint32_t loop_fraction,
                         int32_t position, uint32_t fraction, uint32_t step, uint32_t frames);
int32_t *sxg_oscillator_output(void);
int32_t sxg_oscillator_position(void);
uint32_t sxg_oscillator_fraction(void);
double sxg_envelope_gain(int32_t value);
int sxg_envelope_advance(int32_t *value, int32_t target, int32_t rate);
uint8_t *sxg_sysex_buffer(void);
uint32_t sxg_sysex_capacity(void);
int sxg_sysex(uint32_t length);
int sxg_set_master(float volume);
void sxg_set_effects(uint32_t enabled);
uint32_t sxg_active_voices(void);
uint32_t sxg_channel_info(uint32_t channel, uint32_t field);
uint32_t sxg_voice_envelope(uint32_t voice,uint32_t field);

#endif
