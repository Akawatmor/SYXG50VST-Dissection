import fs from 'node:fs';
import crypto from 'node:crypto';
import {parseMidi} from '../web/midi-file.mjs';
const filename=process.argv[2];if(!filename)throw new Error('Specify the source MIDI path.');
const bytes=fs.readFileSync(filename),song=parseMidi(bytes),rate=44100;
fs.mkdirSync('analysis/veg-song',{recursive:true});
if(song.events.some(e=>e.data[0]===240))throw new Error('This TSV oracle path handles short MIDI only; SysEx requires a separate original-host event path.');
fs.writeFileSync('analysis/veg-song/50938.events.tsv',song.events.map(e=>[Math.round(e.time*rate),e.data[0],e.data[1]||0,e.data[2]||0].join('\t')).join('\n'));
fs.writeFileSync('analysis/veg-song/50938-source.json',JSON.stringify({source:filename,sha256:crypto.createHash('sha256').update(bytes).digest('hex'),rate,duration:song.duration,events:song.events.length,format:song.format,tracks:song.tracks,scheduling:'Original VST wrapper; block 128; input deltaFrames preserved'},null,2));
