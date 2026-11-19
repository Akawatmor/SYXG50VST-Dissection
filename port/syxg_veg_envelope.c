/* Direct translation of VEG RVA 18CF0 / 18EA0 / 18FE0, kept isolated until
   original-voice parameter wiring and render cadence are validated. */
#include <stdint.h>
#include "syxg_veg_envelope.h"
static Envelope env;
static int32_t tables[3][128];
static uint32_t parameters[4];
void *veg_env_buffer(void){return &env;}
void *veg_env_tables(void){return tables;}
void *veg_env_parameters(void){return parameters;}
static double gain(int32_t value){
    if(value<0)return 1;
    if(value>=0xfffff)return 0;
    return ((~(uint32_t)value&65535)|65536)/(131071.0*(1u<<(value>>16)));
}
static int32_t inverse(float value){
    int32_t integer=(int32_t)((double)value*131071.0);
    if(integer<1)return 0xfffff;
    uint32_t bits=(uint32_t)integer,shift=0;
    while(!(bits&65536)){bits<<=1;shift++;}
    return (int32_t)((~bits&65535)|(shift<<16));
}
static int advance(int32_t *value,int32_t target,int32_t rate){
    if(*value==target)return 1;
    if(*value>target){*value-=rate;if(*value<target){*value=target;return 1;}}
    else{*value+=rate;if(*value>target){*value=target;return 1;}}
    return 0;
}
void sxg_veg_env_update(Envelope *state,const int32_t tables[3][128],const uint32_t parameters[4]){
    if(!(state->flags&2))return;
    state->end_target=(int32_t)((parameters[3]&255)<<12);
    uint32_t index=parameters[2]&127;
    if(parameters[2]&128){
        if(state->state==0||state->state==4)state->value=inverse(state->gain);
        state->end_rate=tables[2][index];
        if(index>=96){
            state->state=4;state->flags&=~2u;
            double slope=(gain(state->end_target)-state->gain)/(state->value-state->end_target);
            state->slope=(float)slope;
            state->intercept=(float)(state->value*slope+state->gain);
            state->end_rate=(int32_t)((1.0-gain(0x100000))*0x1p-20*((double)state->end_rate/state->slope));
        }else state->state=3;
    }else state->end_rate=tables[1][index];
}
void sxg_veg_env_init(Envelope *state,const int32_t tables[3][128],const uint32_t parameters[4]){
    state->attack_value=0x80000;
    state->target=(int32_t)((parameters[1]&255)<<12);
    uint32_t index=parameters[0]&127;
    if(!(parameters[0]&128)){
        state->value=0;state->state=(state->target!=0)+1;state->rate=tables[1][index];
        state->gain=1;state->next=1;
    }else{
        state->value=state->target;state->rate=tables[0][index];state->gain=(float)gain(state->value);
        if(!state->target){state->state=3;state->next=state->gain;}
        else{
            state->state=0;
            double slope=(1.0-gain(state->value))/state->target;
            state->slope=(float)slope;state->intercept=(float)(slope*state->target+gain(state->value));
            state->rate=(int32_t)((1.0-gain(0x80000))*0x1p-19*((double)state->rate/state->slope));
            state->next=state->gain;
        }
    }
    sxg_veg_env_update(state,tables,parameters);
}
static float render_store(double value,int truncate){
    union {float f;uint32_t u;} result;
    result.f=(float)value;
    if(truncate){
        if((value>0&&(double)result.f>value)||(value<0&&(double)result.f<value))result.u--;
        if((result.u&0x7f800000u)==0)result.u&=0x80000000u;
    }
    return result.f;
}
static void tick(Envelope *state,int truncate){
    state->gain=state->next;state->flags|=0x2000;
    switch(state->state){
    case 0:
        if(advance(&state->value,0,state->rate))state->state=3;
        state->next=render_store((double)state->intercept-(truncate?render_store((double)state->value*state->slope,1):(double)state->value*state->slope),truncate);break;
    case 1:
        if(advance(&state->attack_value,0,state->rate))state->state=3;
        state->next=1;break;
    case 2:
        if(advance(&state->value,state->target,state->rate))state->state=3;
        state->next=render_store(gain(state->value),truncate);break;
    case 3:
        if(advance(&state->value,state->end_target,state->end_rate))state->flags&=~0x2000u;
        state->next=render_store(gain(state->value),truncate);break;
    case 4:
        if(advance(&state->value,state->end_target,state->end_rate))state->flags&=~0x2000u;
        state->next=render_store((double)state->intercept-(truncate?render_store((double)state->value*state->slope,1):(double)state->value*state->slope),truncate);break;
    }
    if(state->state>1&&state->state<5&&state->next<=gain(0x80000)){
        state->flags=(state->flags&~0x2000u)|0x1000;
        state->end_target=state->target=state->value=0xfffff;state->next=0;
    }
}
void sxg_veg_env_tick(Envelope *state){tick(state,0);}
void sxg_veg_env_tick_render(Envelope *state){tick(state,1);}

void veg_env_update(void){sxg_veg_env_update(&env,tables,parameters);}
void veg_env_init(void){sxg_veg_env_init(&env,tables,parameters);}
void veg_env_tick(void){sxg_veg_env_tick(&env);}
