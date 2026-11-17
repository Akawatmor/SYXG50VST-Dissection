class SyxgProcessor extends AudioWorkletProcessor {
  constructor() {
    super();
    this.core = null;
    this.queue = [];
    this.cursor = 0;
    this.sequence = 0;
    this.telemetry = false;
    this.blocks = 0;
    this.effects = true;
    this.unsupported = 0;
    this.peak = [0, 0];
    this.transportEnd = null;
    this.port.onmessage = ({ data }) => {
      try { this.receive(data); }
      catch (error) { this.port.postMessage({ type: 'error', message: error.message }); }
    };
  }

  receive(message) {
    switch (message.type) {
      case 'init': {
        const instance = new WebAssembly.Instance(message.module, {});
        const core = instance.exports;
        if (message.bank.byteLength !== core.sxg_bank_capacity() || message.wave.byteLength !== core.sxg_wave_capacity()) {
          throw new Error('Bank sizes do not match the S-YXG50 4 MB bank.');
        }
        const bytes = new Uint8Array(core.memory.buffer);
        bytes.set(new Uint8Array(message.bank), core.sxg_bank_buffer());
        bytes.set(new Uint8Array(message.wave), core.sxg_wave_buffer());
        const result = core.sxg_init(message.bank.byteLength, message.wave.byteLength, sampleRate);
        if (result) throw new Error(`Bank initialization failed (${result}).`);
        this.core = core;
        this.pcm = new Float32Array(core.memory.buffer, core.sxg_output_buffer(), 8192);
        this.bytes = bytes;
        this.port.postMessage({ type: 'ready', sampleRate });
        break;
      }
      case 'events': {
        if (!this.core) throw new Error('Load the banks before sending MIDI.');
        const remaining = this.queue.slice(this.cursor);
        const events = message.events.map(event => ({ frame: Math.max(0, Math.round(event.frame)), data: event.data, sequence: this.sequence++ }));
        this.queue = remaining.concat(events).sort((a, b) => a.frame - b.frame || a.sequence - b.sequence);
        this.cursor = 0;
        if (message.endFrame !== undefined) this.transportEnd = message.endFrame;
        break;
      }
      case 'panic':
        this.queue = []; this.cursor = 0; this.transportEnd = null;
        if (this.core) {
          for (let channel = 0; channel < 16; channel++) {
            this.core.sxg_midi(0xb0 | channel, 64, 0);
            this.core.sxg_midi(0xb0 | channel, 120, 0);
          }
          this.core.sxg_set_effects(0);
          this.core.sxg_set_effects(Number(this.effects));
        }
        this.port.postMessage({ type: 'stopped' });
        break;
      case 'master': if (this.core) this.core.sxg_set_master(message.value); break;
      case 'effects': this.effects = Boolean(message.enabled); if (this.core) this.core.sxg_set_effects(Number(this.effects)); break;
      case 'telemetry': this.telemetry = Boolean(message.enabled); break;
      default: throw new Error('Unknown synth message.');
    }
  }

  event(data) {
    if (!data || !data.length) return;
    let result;
    if (data[0] === 0xf0) {
      if (data.length > this.core.sxg_sysex_capacity()) { this.unsupported++; return; }
      this.bytes.set(data, this.core.sxg_sysex_buffer());
      result = this.core.sxg_sysex(data.length);
    } else result = this.core.sxg_midi(data[0], data[1] || 0, data[2] || 0);
    if (result) this.unsupported++;
  }

  process(inputs, outputs) {
    const stereo = outputs[0];
    if (!stereo || !stereo.length || !this.core) return true;
    const left = stereo[0], right = stereo[1] || stereo[0];
    let offset = 0;
    while (offset < left.length) {
      while (this.cursor < this.queue.length && this.queue[this.cursor].frame <= currentFrame + offset) {
        this.event(this.queue[this.cursor++].data);
      }
      let frames = Math.min(4096, left.length - offset);
      if (this.cursor < this.queue.length) frames = Math.min(frames, this.queue[this.cursor].frame - currentFrame - offset);
      if (this.core.sxg_render(frames)) return true;
      for (let frame = 0; frame < frames; frame++) {
        const a = this.pcm[frame * 2], b = this.pcm[frame * 2 + 1];
        left[offset + frame] = a;
        right[offset + frame] = b;
        if (this.telemetry) {
          this.peak[0] = Math.max(this.peak[0], Math.abs(a));
          this.peak[1] = Math.max(this.peak[1], Math.abs(b));
        }
      }
      offset += frames;
    }
    if (this.transportEnd !== null && currentFrame + left.length >= this.transportEnd && this.cursor >= this.queue.length) {
      this.transportEnd = null;
      for (let channel = 0; channel < 16; channel++) {
        this.core.sxg_midi(0xb0 | channel, 64, 0);
        this.core.sxg_midi(0xb0 | channel, 123, 0);
      }
      this.port.postMessage({ type: 'ended' });
    }
    if (this.telemetry && ++this.blocks >= 32) {
      this.blocks = 0;
      const channels = [];
      for (let channel = 0; channel < 16; channel++) channels.push(Array.from({ length: 12 }, (_, field) => this.core.sxg_channel_info(channel, field)));
      this.port.postMessage({ type: 'meters', peak: this.peak, voices: this.core.sxg_active_voices(), channels, unsupported: this.unsupported });
      this.peak = [0, 0];
    }
    return true;
  }
}
registerProcessor('syxg50', SyxgProcessor);
