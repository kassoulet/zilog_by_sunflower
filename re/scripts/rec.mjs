import fs from 'fs'; import {spawn} from 'child_process';
import './node_modules/emulators/dist/emulators.js';
const emulators=globalThis.emulators; emulators.pathPrefix=process.cwd()+'/node_modules/emulators/dist/';
const D='/home/gautier/SynologyDrive/code/current/demos/zilog/';
const exe=new Uint8Array(fs.readFileSync(D+'ZILOG.EXE'));
const conf={dosboxConf:'[cpu]\ncycles=max\n[sblaster]\nsbtype=sb16\n[mixer]\nrate=44100\n[autoexec]\nmount c .\nc:\nSET BLASTER=A220 I7 D1 H5 T6\nZILOG.EXE\n',jsdosConf:{version:'8'}};
const ci=await emulators.dosboxNode([conf,{path:'ZILOG.EXE',contents:exe}]);
const ff=spawn('ffmpeg',['-loglevel','error','-y','-f','rawvideo','-pix_fmt','rgb24','-s','320x200','-framerate','20','-i','-','-c:v','ffv1','ref.mkv'],{stdio:['pipe','inherit','inherit']});
const fr=ci.soundFrequency()||44100; let samples=0, aud=[], last=null, next=0, wrote=0;
ci.events().onSoundPush(s=>{samples+=s.length; aud.push(Float32Array.from(s));});
ci.events().onFrame(rgb=>{ if(!rgb||rgb.length!=192000)return; last=Buffer.from(rgb);
  const t=samples/fr; while(next<=t){ff.stdin.write(last);next+=0.05;wrote++;} });
let done=false; ci.events().onExit(()=>done=true);
const t0=Date.now();
while(!done && next<260 && Date.now()-t0<900000) await new Promise(r=>setTimeout(r,1000));
ff.stdin.end();
const all=new Float32Array(samples); let o=0; for(const a of aud){all.set(a,o);o+=a.length;}
fs.writeFileSync('audio.f32',Buffer.from(all.buffer)); console.log('fr',fr,'samples',samples,'frames',wrote,'done',done,'sec',next);
process.exit(0);
