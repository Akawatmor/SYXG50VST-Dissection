/* Voice allocation, MIDI channel state and stereo rendering. */
#define REVERB_SIZE 16384u
#define CHORUS_SIZE 4096u
static float reverb_delay[4][REVERB_SIZE];
static float chorus_delay[CHORUS_SIZE];
static uint32_t reverb_position[4];
static double reverb_damped[4];
static uint32_t chorus_position;
static double chorus_phase;
static double modulation_phase;

static void reset_effects(void) {
    for (uint32_t tap = 0; tap < 4; ++tap) {
        reverb_position[tap] = 0;
        reverb_damped[tap] = 0;
        for (uint32_t index = 0; index < REVERB_SIZE; ++index) reverb_delay[tap][index] = 0;
    }
    for (uint32_t index = 0; index < CHORUS_SIZE; ++index) chorus_delay[index] = 0;
    chorus_position = 0;
    chorus_phase = 0;
    modulation_phase = 0;
}

static int segment_contains(uint32_t segment, uint32_t address, uint32_t length) {
    return segment < 17 && address <= segments[segment].length && length <= segments[segment].length - address;
}

static double bend_factor(const Channel *channel) {
    double range = channel->bend_semitones + channel->bend_cents / 100.0;
    double bend = ((int32_t)channel->pitch_bend - 8192) / 8192.0;
    return power_of_two((bend * range + channel->transpose) / 12.0);
}

static uint32_t veg_clamp_rate(int rate,int minimum) {
    if(rate<minimum)rate=minimum;
    if(rate>63)rate=63;
    return (uint32_t)rate*2;
}

static void veg_start_envelope(Layer *layer,uint32_t attack,uint32_t decay,uint32_t target,
                               uint32_t release,uint32_t second,uint32_t second_target) {
    if(!veg_rate_tables)return;
    layer->veg_enabled=1;
    layer->veg_envelope.flags=3;
    layer->veg_parameters[0]=attack^128u;
    layer->veg_parameters[1]=attack&128u?0:255;
    layer->veg_parameters[2]=decay;
    layer->veg_parameters[3]=target;
    layer->veg_release_rate=release;
    layer->veg_second_rate=second;
    layer->veg_second_target=second_target;
    sxg_veg_env_init(&layer->veg_envelope,veg_rate_tables,layer->veg_parameters);
}

static int select_prevoice(const Channel *channel, uint32_t *segment, uint32_t *offset) {
    uint32_t selector;
    uint32_t table = 12;
    if (reset_mode == 0 && channel->bank_msb < segments[7].length) {
        selector = bank_data[segments[7].offset + channel->bank_msb];
        if (selector == 255) selector = 0;
        else table = 11;
    } else if (channel->bank_msb == 121) {
        if (!segment_contains(10, channel->bank_lsb, 1)) return SXG_BAD_BANK;
        selector = bank_data[segments[10].offset + channel->bank_lsb];
    } else {
        if (!segment_contains(8, channel->bank_msb, 1)) return SXG_BAD_BANK;
        selector = bank_data[segments[8].offset + channel->bank_msb];
        if (selector == 1) selector = bank_data[segments[9].offset + channel->bank_lsb];
    }
    uint32_t address = (selector * 128 + channel->program) * 2;
    if (!segment_contains(table, address, 2)) return SXG_BAD_BANK;
    uint32_t record = read_le16(bank_data + segments[table].offset + address);
    *segment = (record & 0x8000u) ? 14 : 13;
    *offset = (record & 0x7FFFu) * 2;
    return segment_contains(*segment, *offset, 2) ? SXG_OK : SXG_BAD_BANK;
}

static int configure_sample(Layer *layer, uint32_t base, uint32_t before_loop, uint32_t loop_length,
                            uint32_t flags, int root, int cents, int target, uint32_t velocity) {
    uint32_t bytes = (flags & 128u) ? 1 : 2;
    if (base > loaded_wave_size || before_loop > base / bytes ||
        loop_length > (loaded_wave_size - base) / bytes || before_loop + loop_length < 2) return SXG_BAD_SAMPLE;
    layer->sample_start = base - before_loop * bytes;
    layer->sample_base = base;
    layer->sample_end = base + loop_length * bytes;
    layer->bytes_per_sample = bytes;
    layer->sample_count = before_loop + loop_length;
    layer->loop_start = before_loop;
    layer->looping = loop_length > 0;
    layer->loop_fraction = (flags & 63u) << 9;
    layer->flags = flags;
    layer->root_key = (uint32_t)root;
    layer->position = 0;
    double semitones = target - root + cents / 100.0;
    layer->base_step = (44100.0 / output_rate) * power_of_two(semitones / 12.0);
    layer->step_q15 = (uint32_t)(layer->base_step * 2048.0 + 0.5) * 16;
    layer->base_step = layer->step_q15 / 32768.0;
    layer->step = layer->base_step * bend_factor(channels + layer->channel);
    layer->gain = 0.25 * (double)velocity * velocity / (127.0 * 127.0);
    layer->release_gain = 1;
    layer->attack_gain = 0;
    layer->key_down = 1;
    layer->receive_note_off = 1;
    layer->active = 1;
    layer->pan = 0.5;
    layer->reverb_send = 1;
    layer->chorus_send = 1;
    return SXG_OK;
}

static int configure_element(Layer *layer, const uint8_t *element, uint32_t note, uint32_t velocity) {
    uint32_t directory = element[0] * 2u;
    if (!segment_contains(15, directory, 2)) return SXG_BAD_BANK;
    uint32_t record = read_le16(bank_data + segments[15].offset + directory);
    const uint8_t *wave;
    for (;;) {
        if (!segment_contains(16, record, 16)) return SXG_BAD_BANK;
        wave = bank_data + segments[16].offset + record;
        if (note <= (wave[15] & 127u) || (wave[15] & 128u)) break;
        record += 16;
    }
    layer->record_offset = record;
    int result = configure_sample(layer, read_be24(wave + 9), read_be24(wave + 3), read_be24(wave + 6),
                            wave[12], (int8_t)wave[1], (int8_t)wave[2], (int)note, velocity);
    if(!result){
        /* VEG 15770: key-rate scaling truncates toward zero, then stores int8. */
        int scaling=(int8_t)(((int)note-element[0x43])*((int)element[0x42]-64)*16/256);
        uint32_t attack=element[0x45]?element[0x45]*2u:8u;
        if(attack==126)attack=255;
        veg_start_envelope(layer,attack,veg_clamp_rate((int8_t)(element[0x46]+scaling),1),
            (uint8_t)(-2*(element[0x49]+1)),veg_clamp_rate(element[0x48]+scaling,1),
            veg_clamp_rate(element[0x47]+scaling,0),(uint8_t)(-2*(element[0x4a]+1)));
    }
    return result;
}

static uint32_t allocate_voice(void) {
    uint32_t candidate = 0;
    for (uint32_t index = 0; index < MAX_VOICES; ++index) {
        if (!layers[index].active) return index;
        if ((layers[index].releasing && !layers[candidate].releasing) ||
            (layers[index].releasing == layers[candidate].releasing && layers[index].age < layers[candidate].age)) candidate = index;
    }
    return candidate;
}

static int configure_drum(Layer *layer, const Channel *channel, uint32_t note, uint32_t velocity) {
    uint32_t kit_table = reset_mode == 0 ? 0 : 1;
    if (channel->bank_msb == 126) kit_table = 2;
    if (channel->bank_msb == 120) kit_table = 3;
    if (!segment_contains(kit_table, channel->program, 1)) return SXG_BAD_BANK;
    uint32_t kit = bank_data[segments[kit_table].offset + channel->program];
    uint32_t map = (kit * 128 + note) * 2;
    if (!segment_contains(4, map, 2)) return SXG_BAD_BANK;
    uint32_t record = read_le16(bank_data + segments[4].offset + map);
    if (record == 65535) return SXG_UNSUPPORTED;
    if (!segment_contains(5, record, 30)) return SXG_BAD_BANK;
    const uint8_t *drum = bank_data + segments[5].offset + record;
    if (drum[16] == 0) {
        uint32_t address = drum[17] * 2u;
        if (!segment_contains(6, address, 2)) return SXG_BAD_BANK;
        uint32_t definition = read_le16(bank_data + segments[6].offset + address) * 2u;
        if (!segment_contains(13, definition, 80)) return SXG_BAD_BANK;
        int result = configure_element(layer, bank_data + segments[13].offset + definition + 2, note, velocity);
        if (result) return result;
    } else {
        uint32_t base = read_be24(drum + 24);
        uint32_t before = (uint32_t)drum[19] << 8 | drum[20];
        uint32_t loop = (uint32_t)drum[22] << 8 | drum[23];
        int target = (int)drum[18] + (int)drum[0] - 64;
        int result = configure_sample(layer, base, before, loop, drum[27], drum[18], (int)drum[1] - 64, target, velocity);
        if (result) return result;
    }
    layer->exclusive_group = drum[3];
    layer->pan = drum[4] ? drum[4] / 127.0 : 0.5;
    layer->gain *= drum[2] / 127.0;
    /* Original FUN_10016620 scales part sends by drum record bytes 5/6. */
    layer->reverb_send = drum[5] / 128.0;
    layer->chorus_send = drum[6] / 128.0;
    layer->receive_note_off = drum[9] != 0;
    if(drum[16]!=0){
        /* VEG 139A0 defaults, 12310 + 124F0; neutral per-note edits are 64. */
        uint32_t attack=((drum[13]>>1)*2u)+33u;
        if(attack<32)attack=32;
        if(attack<128){
            if(attack==127)attack=255;
            veg_start_envelope(layer,attack,drum[14],4,
                veg_clamp_rate(drum[15]>>1,0),veg_clamp_rate(drum[15]>>1,0),255);
        }else{
            attack=(uint8_t)(126u-attack);
            veg_start_envelope(layer,attack,drum[15],255,
                veg_clamp_rate(drum[15]>>1,0),veg_clamp_rate(drum[15]>>1,0),255);
            layer->veg_second_sent=1;
        }
    }
    /* One-shot samples already contain their acoustic decay. Looped percussion
       still needs a provisional envelope until the original AEG is recovered. */
    double decay = note == 42 || note == 44 ? 0.02 : note == 46 ? 0.10 : 0.18;
    layer->decay_multiplier = layer->looping ? power_of_two(-1.0 / (output_rate * decay)) : 0;
    return SXG_OK;
}

static int note_on(uint32_t channel_number, uint32_t note, uint32_t velocity) {
    const Channel *channel = channels + channel_number;
    Layer pending[MAX_LAYERS] = {0};
    uint32_t count = 0;
    if (channel->drum || channel->bank_msb >= 126) {
        pending[0].channel = channel_number;
        int error = configure_drum(pending, channel, note, velocity);
        if (error) return error;
        count = 1;
    } else {
        uint32_t segment, record;
        int error = select_prevoice(channel, &segment, &record);
        if (error) return error;
        const uint8_t *prevoice = bank_data + segments[segment].offset + record;
        uint32_t elements = (prevoice[1] & 2u) ? 2 : 1;
        if (!segment_contains(segment, record, 2 + elements * 78)) return SXG_BAD_BANK;
        for (uint32_t index = 0; index < elements; ++index) {
            if (!(prevoice[1] & (1u << index))) continue;
            const uint8_t *element = prevoice + 2 + index * 78;
            int key_difference = (int)note - element[1];
            int velocity_difference = (int)velocity - element[3];
            if (key_difference < 0) key_difference = -key_difference;
            if (velocity_difference < 0) velocity_difference = -velocity_difference;
            if ((uint32_t)key_difference > element[2] || (uint32_t)velocity_difference > element[4]) continue;
            pending[count].channel = channel_number;
            error = configure_element(pending + count, element, note, velocity);
            if (error) return error;
            ++count;
        }
    }
    if (!count) return SXG_UNSUPPORTED;
    for (uint32_t index = 0; index < count; ++index) {
        if (pending[index].exclusive_group) {
            for (uint32_t old = 0; old < MAX_VOICES; ++old) {
                if (layers[old].channel == channel_number && layers[old].exclusive_group == pending[index].exclusive_group) {
                    layers[old].releasing = 1;
                    layers[old].choked = 1;
                }
            }
        }
        uint32_t slot = allocate_voice();
        pending[index].note = note;
        pending[index].age = ++voice_age;
        layers[slot] = pending[index];
        selected_indices[index] = slot;
    }
    selected_layers = count;
    return SXG_OK;
}

static void release_channel(uint32_t number, int immediate) {
    for (uint32_t index = 0; index < MAX_VOICES; ++index) {
        Layer *layer = layers + index;
        if (layer->channel != number) continue;
        layer->key_down = 0;
        if (immediate) layer->active = 0;
        else if (!channels[number].sustain) layer->releasing = 1;
    }
}

static void update_bend(uint32_t channel) {
    double factor = bend_factor(channels + channel);
    for (uint32_t index = 0; index < MAX_VOICES; ++index) {
        if (layers[index].channel == channel) layers[index].step = layers[index].base_step * factor;
    }
}

static int controller(uint32_t number, uint32_t control, uint32_t value) {
    Channel *channel = channels + number;
    switch (control) {
    case 0: channel->bank_msb = value; break;
    case 1: channel->modulation = value; break;
    case 7: channel->volume = value; break;
    case 10: channel->pan = value; break;
    case 11: channel->expression = value; break;
    case 32: channel->bank_lsb = value; break;
    case 64:
        channel->sustain = value >= 64;
        if (!channel->sustain) {
            for (uint32_t index = 0; index < MAX_VOICES; ++index) {
                if (layers[index].channel == number && !layers[index].key_down && layers[index].receive_note_off) layers[index].releasing = 1;
            }
        }
        break;
    case 74: channel->cutoff = value; break;
    case 71: channel->resonance = value; break;
    case 91: channel->reverb = value; break;
    case 93: channel->chorus = value; break;
    case 100: channel->rpn_lsb = value; break;
    case 101: channel->rpn_msb = value; break;
    case 6:
        if (channel->rpn_msb == 0 && channel->rpn_lsb == 0) channel->bend_semitones = value;
        else if (channel->rpn_msb == 0 && channel->rpn_lsb == 2) channel->transpose = (int)value - 64;
        update_bend(number);
        break;
    case 38:
        if (channel->rpn_msb == 0 && channel->rpn_lsb == 0) channel->bend_cents = value > 99 ? 99 : value;
        update_bend(number);
        break;
    case 120: release_channel(number, 1); break;
    case 121:
        channel->sustain = 0; channel->expression = 127; channel->modulation = 0;
        channel->pitch_bend = 8192; channel->rpn_msb = 127; channel->rpn_lsb = 127;
        controller(number, 64, 0); update_bend(number);
        break;
    case 123: release_channel(number, 0); break;
    default: return SXG_UNSUPPORTED;
    }
    return SXG_OK;
}

int sxg_midi(uint32_t status, uint32_t data1, uint32_t data2) {
    if (!initialized) return SXG_NOT_INITIALIZED;
    if (status > 255 || data1 > 127 || data2 > 127 || status < 128) return SXG_BAD_ARGUMENT;
    if (status == 255) { sxg_reset(); return SXG_OK; }
    uint32_t number = status & 15u;
    Channel *channel = channels + number;
    switch (status & 0xF0u) {
    case 0xC0: channel->program = data1; return SXG_OK;
    case 0xB0: return controller(number, data1, data2);
    case 0xE0: channel->pitch_bend = data1 | data2 << 7; update_bend(number); return SXG_OK;
    case 0xA0: case 0xD0: return SXG_UNSUPPORTED;
    case 0x90: if (data2) return note_on(number, data1, data2);
        /* fall through */
    case 0x80:
        for (uint32_t index = 0; index < MAX_VOICES; ++index) {
            Layer *layer = layers + index;
            if (layer->active && layer->channel == number && layer->note == data1 && layer->key_down) {
                layer->key_down = 0;
                if (!channel->sustain && layer->receive_note_off) layer->releasing = 1;
            }
        }
        return SXG_OK;
    default: return SXG_UNSUPPORTED;
    }
}

uint8_t *sxg_sysex_buffer(void) { return sysex_buffer; }
uint32_t sxg_sysex_capacity(void) { return sizeof(sysex_buffer); }

int sxg_sysex(uint32_t length) {
    if (!initialized) return SXG_NOT_INITIALIZED;
    if (length < 4 || length > sizeof(sysex_buffer) || sysex_buffer[0] != 0xF0 || sysex_buffer[length-1] != 0xF7) return SXG_BAD_ARGUMENT;
    for (uint32_t index = 1; index + 1 < length; ++index) {
        if (sysex_buffer[index] > 127) return SXG_BAD_ARGUMENT;
    }
    const uint8_t *data = sysex_buffer;
    if (length == 6 && data[1] == 0x7E && data[3] == 9 && (data[4] == 1 || data[4] == 3)) {
        sxg_reset(); reset_mode = 1; return SXG_OK;
    }
    if (length == 9 && data[1] == 0x43 && data[3] == 0x4C && data[4] == 0 && data[5] == 0 && data[6] == 0x7E && data[7] == 0) {
        sxg_reset(); reset_mode = 1; return SXG_OK;
    }
    if (length == 11 && data[1] == 0x41 && data[3] == 0x42 && data[4] == 0x12 && data[5] == 0x40 && data[6] == 0 && data[7] == 0x7F && data[8] == 0 && data[9] == 0x41) {
        sxg_reset(); reset_mode = 0; return SXG_OK;
    }
    if (length == 8 && data[1] == 0x7F && data[3] == 4 && data[4] == 1) {
        master_volume = (float)(data[5] | data[6] << 7) / 16383.0f; return SXG_OK;
    }
    if (length == 9 && data[1] == 0x43 && data[3] == 0x4C && data[4] == 0 && data[5] == 0 && data[6] == 4) {
        master_volume = data[7] / 127.0f; return SXG_OK;
    }
    if (length == 9 && data[1] == 0x43 && data[3] == 0x4C && data[4] == 8 && data[5] < 16) {
        uint32_t part = data[5];
        switch (data[6]) {
        case 1: channels[part].bank_msb = data[7]; break;
        case 2: channels[part].bank_lsb = data[7]; break;
        case 3: channels[part].program = data[7]; break;
        case 7: channels[part].drum = data[7] != 0; break;
        case 11: channels[part].volume = data[7]; break;
        case 14: channels[part].pan = data[7]; break;
        default: return SXG_UNSUPPORTED;
        }
        return SXG_OK;
    }
    return SXG_UNSUPPORTED;
}

int sxg_set_master(float volume) {
    if (!(volume >= 0 && volume <= 1)) return SXG_BAD_ARGUMENT;
    master_volume = volume; return SXG_OK;
}

void sxg_set_effects(uint32_t enabled) {
    effects_enabled = enabled != 0;
    if (!effects_enabled) reset_effects();
}

uint32_t sxg_active_voices(void) {
    uint32_t count = 0;
    for (uint32_t index = 0; index < MAX_VOICES; ++index) count += layers[index].active != 0;
    return count;
}

uint32_t sxg_channel_info(uint32_t channel, uint32_t field) {
    if (channel >= 16) return 0;
    const Channel *state = channels + channel;
    switch (field) {
    case 0: return state->program;
    case 1: return state->volume;
    case 2: return state->expression;
    case 3: return state->pan;
    case 4: return state->sustain;
    case 5: return state->pitch_bend;
    case 6: return state->bank_msb;
    case 7: return state->bank_lsb;
    case 8: return state->drum;
    case 9: return state->reverb;
    case 10: return state->chorus;
    case 11: {
        uint32_t count = 0;
        for (uint32_t index = 0; index < MAX_VOICES; ++index) count += layers[index].active && layers[index].channel == channel;
        return count;
    }
    default: return 0;
    }
}

static double sample_at(const Layer *layer, uint32_t frame) {
    uint32_t address = layer->sample_start + frame * layer->bytes_per_sample;
    if (layer->bytes_per_sample == 1) return ((int32_t)(wave_data[address] ^ 0x5C) - 128) / 128.0;
    return ((int32_t)(read_le16(wave_data + address) ^ 0x5C5Cu) - 32768) / 32768.0;
}

static void process_effects(double reverb_send, double chorus_send, double damping, double *left, double *right) {
    static const uint32_t delay_ms[4] = {31, 37, 41, 43};
    double wet[4];
    for (uint32_t tap = 0; tap < 4; ++tap) {
        uint32_t length = output_rate * delay_ms[tap] / 1000;
        if (length >= REVERB_SIZE) length = REVERB_SIZE-1;
        uint32_t position = reverb_position[tap];
        wet[tap] = reverb_delay[tap][position];
        reverb_damped[tap] += damping * (wet[tap] - reverb_damped[tap]);
        reverb_delay[tap][position] = (float)(reverb_send * 0.10 + reverb_damped[tap] * (0.65 - tap * 0.025));
        reverb_position[tap] = position + 1 >= length ? 0 : position + 1;
    }
    *left += (wet[0] + wet[2]) * 0.18;
    *right += (wet[1] + wet[3]) * 0.18;
    chorus_phase += 0.45 / output_rate;
    if (chorus_phase >= 1) chorus_phase -= 1;
    double triangle = chorus_phase < 0.5 ? chorus_phase * 4 - 1 : 3 - chorus_phase * 4;
    double offset = output_rate * (0.012 + triangle * 0.002);
    if (offset > CHORUS_SIZE - 2) offset = CHORUS_SIZE - 2;
    uint32_t delay = (uint32_t)offset;
    uint32_t read = (chorus_position + CHORUS_SIZE - delay) % CHORUS_SIZE;
    double fraction = offset - delay;
    chorus_delay[chorus_position] = (float)chorus_send;
    /* Fractional delay avoids one-sample jumps on bright drum transients. */
    uint32_t previous = (read + CHORUS_SIZE - 1) % CHORUS_SIZE;
    *left += (chorus_delay[read] * (1-fraction) + chorus_delay[previous] * fraction) * 0.14;
    read = (read + 17) % CHORUS_SIZE;
    previous = (read + CHORUS_SIZE - 1) % CHORUS_SIZE;
    *right += (chorus_delay[read] * (1-fraction) + chorus_delay[previous] * fraction) * 0.14;
    chorus_position = (chorus_position + 1) % CHORUS_SIZE;
}

int sxg_render(uint32_t frames) {
    if (!initialized) return SXG_NOT_INITIALIZED;
    if (!frames || frames > OUTPUT_FRAMES) return SXG_BAD_ARGUMENT;
    double release = power_of_two(-1.0 / (output_rate * 0.035));
    double choke = power_of_two(-1.0 / (output_rate * 0.003));
    double damping = 1.0 - power_of_two(-6000.0 / output_rate);
    for (uint32_t frame = 0; frame < frames; ++frame) {
        int control_tick=0;
        if(render_phase==0){
            control_frames+=128;
            if(control_frames>=output_rate/100){
                control_frames-=output_rate/100;control_tick=(++control_ticks&1u)==0;
            }
        }
        for(uint32_t index=0;index<MAX_VOICES;index++){
            Layer *layer=layers+index;
            if(!layer->active||!layer->veg_enabled)continue;
            if(layer->releasing&&!layer->veg_release_sent){
                layer->veg_parameters[2]=layer->choked?254:layer->veg_release_rate|128u;
                layer->veg_parameters[3]=255;
                sxg_veg_env_update(&layer->veg_envelope,veg_rate_tables,layer->veg_parameters);
                layer->veg_release_sent=1;
            }else if(control_tick&&!layer->releasing&&!layer->veg_second_sent&&
                     layer->veg_envelope.state>=3&&!(layer->veg_envelope.flags&0x2000)){
                layer->veg_parameters[2]=layer->veg_second_rate;
                layer->veg_parameters[3]=layer->veg_second_target;
                sxg_veg_env_update(&layer->veg_envelope,veg_rate_tables,layer->veg_parameters);
                layer->veg_second_sent=1;
            }
            if(render_phase==0)sxg_veg_env_tick_render(&layer->veg_envelope);
            if(layer->veg_envelope.flags&0x1000)layer->active=0;
        }
        double left = 0, right = 0, reverb_send = 0, chorus_send = 0;
        modulation_phase += 5.0 / output_rate;
        if (modulation_phase >= 1) modulation_phase -= 1;
        double vibrato = modulation_phase < 0.5 ? modulation_phase*4-1 : 3-modulation_phase*4;
        for (uint32_t index = 0; index < MAX_VOICES; ++index) {
            Layer *layer = layers + index;
            if (!layer->active) continue;
            const Channel *channel = channels + layer->channel;
            uint32_t position = (uint32_t)layer->position;
            uint32_t next = position + 1;
            if (next >= layer->sample_count) next = layer->looping ? layer->loop_start : position;
            double fraction = layer->position - position;
            double first = sample_at(layer, position), second = sample_at(layer, next);
            double sample = first * (32767.0 / 32768.0 - fraction) + second * fraction;
            double cutoff = 0.08 + channel->cutoff * 0.007;
            if (cutoff > 0.98) cutoff = 0.98;
            double resonance = channel->resonance / 127.0 * 0.45;
            sample -= resonance * (layer->filter_state - layer->filter_state2);
            layer->filter_state += cutoff * (sample - layer->filter_state);
            layer->filter_state2 += cutoff * (layer->filter_state - layer->filter_state2);
            layer->attack_gain += 1.0 / (output_rate * 0.002);
            if (layer->attack_gain > 1) layer->attack_gain = 1;
            double envelope=layer->release_gain*layer->attack_gain;
            if(layer->veg_enabled)envelope=layer->veg_envelope.gain+
                ((double)layer->veg_envelope.next-layer->veg_envelope.gain)*render_phase/128.0;
            double amplitude = layer->gain * envelope * channel->volume * channel->expression / (127.0 * 127.0);
            sample = -layer->filter_state2 * amplitude;
            double pan = layer->pan + ((int)channel->pan - 64) / 127.0;
            if (pan < 0) pan = 0;
            if (pan > 1) pan = 1;
            left += sample * (1-pan);
            right += sample * pan;
            /* Match the center-panned dry level before feeding the wet buses. */
            reverb_send += sample * 0.5 * layer->reverb_send * channel->reverb / 127.0;
            chorus_send += sample * 0.5 * layer->chorus_send * channel->chorus / 127.0;
            layer->position += layer->step * (1 + vibrato * channel->modulation / 127.0 * 0.012);
            while (layer->position >= layer->sample_count) {
                if (!layer->looping) { layer->active = 0; break; }
                layer->position -= layer->sample_count - layer->loop_start;
                layer->position += layer->loop_fraction / 32768.0;
            }
            if (!layer->veg_enabled && layer->releasing) {
                layer->release_gain *= layer->choked ? choke : release;
            }
            if (!layer->veg_enabled && layer->decay_multiplier > 0) {
                layer->release_gain *= layer->decay_multiplier;
            }
            if (layer->release_gain < 1e-7) layer->active = 0;
        }
        if (effects_enabled) process_effects(reverb_send, chorus_send, damping, &left, &right);
        left *= master_volume; right *= master_volume;
        if (left > 1) left = 1;
        if (left < -1) left = -1;
        if (right > 1) right = 1;
        if (right < -1) right = -1;
        output[frame*2] = (float)left;
        output[frame*2+1] = (float)right;
        render_phase=(render_phase+1)&127u;
    }
    return SXG_OK;
}

uint32_t sxg_layer_info(uint32_t index, uint32_t field) {
    if (index >= selected_layers) return 0;
    const Layer *layer = layers + selected_indices[index];
    switch (field) {
    case 0: return layer->record_offset;
    case 1: return layer->sample_start;
    case 2: return layer->sample_base;
    case 3: return layer->sample_end;
    case 4: return layer->bytes_per_sample;
    case 5: return layer->root_key;
    case 6: return layer->flags;
    case 7: return layer->step_q15;
    default: return 0;
    }
}

uint32_t sxg_voice_envelope(uint32_t voice,uint32_t field){
    if(voice>=MAX_VOICES)return 0;
    if(field<12){
        /* Read object representation without type-punning alias violations. */
        const uint8_t *bytes=(const uint8_t *)&layers[voice].veg_envelope;
        return read_le32(bytes+field*4);
    }
    if(field<16)return layers[voice].veg_parameters[field-12];
    return field==16?layers[voice].veg_enabled:0;
}
