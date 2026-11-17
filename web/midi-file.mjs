export function parseMidi(buffer) {
  const bytes = buffer instanceof Uint8Array ? buffer : new Uint8Array(buffer);
  const view = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
  let position = 0, serial = 0, limit = bytes.length;
  const need = count => { if (count < 0 || position + count > limit) throw new Error('MIDI file or track is truncated.'); };
  const byte = () => { need(1); return bytes[position++]; };
  const u16 = () => { need(2); const value = view.getUint16(position); position += 2; return value; };
  const u32 = () => { need(4); const value = view.getUint32(position); position += 4; return value; };
  const text = count => { need(count); const value = String.fromCharCode(...bytes.subarray(position, position + count)); position += count; return value; };
  const variable = () => {
    let value = 0;
    for (let count = 0; count < 4; count++) { const next = byte(); value = value * 128 + (next & 127); if (!(next & 128)) return value; }
    throw new Error('Invalid MIDI variable length.');
  };
  if (text(4) !== 'MThd') throw new Error('Select a Standard MIDI File (.mid).');
  const headerLength = u32();
  if (headerLength < 6) throw new Error('Invalid MIDI header.');
  const format = u16(), trackCount = u16(), division = u16();
  if (format > 1) throw new Error('MIDI format 2 contains independent songs. Use format 0 or 1.');
  if (!trackCount || !division) throw new Error('Invalid MIDI timing.');
  need(headerLength - 6); position += headerLength - 6;
  const merged = [];
  let endTick = 0;
  for (let track = 0; track < trackCount; track++) {
    if (text(4) !== 'MTrk') throw new Error('MIDI track header is missing.');
    const length = u32(); need(length);
    const end = position + length;
    limit = end;
    let tick = 0, running = 0, sysex = [];
    while (position < end) {
      tick += variable();
      let status = byte();
      if (status < 128) { if (!running) throw new Error('Invalid MIDI running status.'); position--; status = running; }
      if (status === 0xff) {
        const type = byte(), count = variable(); need(count);
        if (type === 0x51 && count === 3) {
          const tempo = bytes[position] * 65536 + bytes[position + 1] * 256 + bytes[position + 2];
          if (!tempo) throw new Error('Invalid MIDI tempo.');
          merged.push({ tick, tempo, serial: serial++ });
        }
        position += count;
        if (type === 0x2f) { endTick = Math.max(endTick, tick); break; }
      } else if (status === 0xf0 || status === 0xf7) {
        running = 0;
        const count = variable(); need(count);
        if (status === 0xf0) sysex = [0xf0];
        if (sysex.length + count > 1024) throw new Error('SysEx message exceeds the engine limit of 1,024 bytes.');
        for (let index = 0; index < count; index++) sysex.push(bytes[position + index]);
        position += count;
        if (sysex[sysex.length - 1] === 0xf7 && sysex[0] === 0xf0) { merged.push({ tick, data: sysex, serial: serial++ }); sysex = []; }
      } else {
        if (status >= 0xf0) throw new Error('Unsupported MIDI system event in track.');
        running = status;
        const count = (status & 0xf0) === 0xc0 || (status & 0xf0) === 0xd0 ? 1 : 2;
        const data = [status];
        for (let index = 0; index < count; index++) { const value = byte(); if (value >= 128) throw new Error('Invalid MIDI data byte.'); data.push(value); }
        merged.push({ tick, data, serial: serial++ });
      }
      if (position > end) throw new Error('MIDI event extends beyond its track.');
      if (merged.length > 250000) throw new Error('This MIDI file exceeds 250,000 events.');
    }
    endTick = Math.max(endTick, tick);
    position = end;
    limit = bytes.length;
  }
  merged.sort((a, b) => a.tick - b.tick || a.serial - b.serial);
  let seconds = 0, tick = 0, tempo = 500000;
  let smpte = 0;
  if (division & 0x8000) {
    const frames = 256 - (division >> 8), ticksPerFrame = division & 255;
    if (![24, 25, 29, 30].includes(frames) || !ticksPerFrame) throw new Error('Invalid SMPTE timing.');
    smpte = (frames === 29 ? 30000 / 1001 : frames) * ticksPerFrame;
  }
  const events = [];
  for (const event of merged) {
    seconds += (event.tick - tick) * (smpte ? 1 / smpte : tempo / 1000000 / division);
    tick = event.tick;
    if (event.tempo) tempo = event.tempo;
    else events.push({ time: seconds, data: event.data });
  }
  seconds += (endTick - tick) * (smpte ? 1 / smpte : tempo / 1000000 / division);
  return { events, duration: seconds, format, tracks: trackCount };
}
