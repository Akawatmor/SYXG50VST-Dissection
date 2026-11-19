"""Build the original-derived envelope in isolation, without updating playback."""
from pathlib import Path
import os,subprocess
ROOT=Path(__file__).resolve().parents[1]
env=os.environ.copy()
env['ZIG_GLOBAL_CACHE_DIR']=str(ROOT/'.tools/zig-global-cache')
env['ZIG_LOCAL_CACHE_DIR']=str(ROOT/'.tools/zig-local-cache')
source=str(ROOT/'port/syxg_veg_envelope.c')
flags=['-std=c11','-O2','-Wall','-Wextra','-Werror','-ffp-contract=off','-fno-fast-math']
subprocess.run(['gcc',*flags,'-shared',source,'-o',str(ROOT/'build/veg_envelope.dll')],check=True)
exports=['veg_env_buffer','veg_env_tables','veg_env_parameters','veg_env_update','veg_env_init','veg_env_tick']
subprocess.run([str(ROOT/'.tools/zig-x86_64-windows-0.15.2/zig.exe'),'cc',*flags,source,'--target=wasm32-freestanding','-nostdlib','-Wl,--no-entry','-Wl,--export-memory',*['-Wl,--export='+name for name in exports],'-o',str(ROOT/'build/veg_envelope.wasm')],check=True,env=env)
