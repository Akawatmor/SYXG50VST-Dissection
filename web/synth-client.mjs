export class SyxgSynth extends EventTarget {
  constructor() {
    super();
    this.context = null;
    this.node = null;
    this.ready = false;
    this.master = 0.8;
    this.effects = true;
  }

  async load(bank, wave, options = {}) {
    if (this.context) await this.close();
    this.context = new AudioContext({ latencyHint: 'interactive', sampleRate: options.sampleRate || 48000 });
    await this.context.resume();
    try {
      const response = await fetch(new URL('./syxg_core.wasm', import.meta.url));
      if (!response.ok) throw new Error('WASM could not be loaded. Build the project first.');
      const module = await WebAssembly.compile(await response.arrayBuffer());
      await this.context.audioWorklet.addModule(new URL('./synth-worklet.js', import.meta.url));
      this.node = new AudioWorkletNode(this.context, 'syxg50', { numberOfInputs: 0, numberOfOutputs: 1, outputChannelCount: [2] });
      await new Promise((resolve, reject) => {
        const timer = setTimeout(() => reject(new Error('Audio engine initialization timed out.')), 15000);
        this.node.port.onmessage = ({ data }) => {
          if (data.type === 'ready') { clearTimeout(timer); resolve(); }
          if (data.type === 'error') { clearTimeout(timer); reject(new Error(data.message)); }
          this.dispatchEvent(new CustomEvent(data.type, { detail: data }));
        };
        const bankCopy = bank.slice().buffer, waveCopy = wave.slice().buffer;
        this.node.port.postMessage({ type: 'init', module, bank: bankCopy, wave: waveCopy }, [bankCopy, waveCopy]);
      });
      this.node.addEventListener('processorerror', () => this.dispatchEvent(new CustomEvent('error', { detail: { message: 'Audio processor stopped. Restart the engine.' } })));
      this.node.connect(this.context.destination);
      this.ready = true;
      this.setMaster(this.master);
      this.setEffects(this.effects);
      return this;
    } catch (error) { await this.close(); throw error; }
  }

  send(data, time = this.context?.currentTime || 0) {
    if (!this.ready) throw new Error('Start the engine first.');
    this.node.port.postMessage({ type: 'events', events: [{ frame: Math.round(time * this.context.sampleRate), data: Array.from(data) }] });
  }

  play(events, duration) {
    if (!this.ready) throw new Error('Start the engine first.');
    this.panic();
    const start = this.context.currentTime + 0.1;
    this.node.port.postMessage({ type: 'events', events: events.map(event => ({ frame: Math.round((start + event.time) * this.context.sampleRate), data: event.data })),
      endFrame: Math.round((start + duration) * this.context.sampleRate) });
    return start;
  }

  panic() { this.node?.port.postMessage({ type: 'panic' }); }
  setMaster(value) { this.master = Math.max(0, Math.min(1, value)); this.node?.port.postMessage({ type: 'master', value: this.master }); }
  setEffects(enabled) { this.effects = Boolean(enabled); this.node?.port.postMessage({ type: 'effects', enabled: this.effects }); }
  setTelemetry(enabled) { this.node?.port.postMessage({ type: 'telemetry', enabled }); }
  async pause() { if (this.context) await this.context.suspend(); }
  async resume() { if (this.context) await this.context.resume(); }
  async close() {
    this.ready = false;
    this.node?.disconnect();
    this.node?.port.close();
    this.node = null;
    if (this.context && this.context.state !== 'closed') await this.context.close();
    this.context = null;
  }
}
