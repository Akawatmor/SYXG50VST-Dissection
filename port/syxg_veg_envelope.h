#ifndef SYXG_VEG_ENVELOPE_H
#define SYXG_VEG_ENVELOPE_H
#include <stdint.h>
typedef struct {
    uint32_t flags;
    int32_t state,value,target,end_target,rate,end_rate,attack_value;
    float gain,next,slope,intercept;
} Envelope;
void sxg_veg_env_init(Envelope *state,const int32_t tables[3][128],const uint32_t parameters[4]);
void sxg_veg_env_update(Envelope *state,const int32_t tables[3][128],const uint32_t parameters[4]);
void sxg_veg_env_tick(Envelope *state);
void sxg_veg_env_tick_render(Envelope *state);
#endif
