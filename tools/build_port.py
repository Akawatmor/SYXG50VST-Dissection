"""Build the same C core for Windows x64 and freestanding WebAssembly."""
from pathlib import Path
import subprocess
import os

ROOT = Path(__file__).resolve().parents[1]
ZIG = ROOT / ".tools/zig-x86_64-windows-0.15.2/zig.exe"
OUT = ROOT / "build"
OUT.mkdir(exist_ok=True)
environment = os.environ.copy()
environment["ZIG_GLOBAL_CACHE_DIR"] = str(ROOT / ".tools/zig-global-cache")
environment["ZIG_LOCAL_CACHE_DIR"] = str(ROOT / ".tools/zig-local-cache")
flags = ["-std=c11", "-O2", "-Wall", "-Wextra", "-Werror", "-ffp-contract=off", "-fno-fast-math", str(ROOT/"port/syxg_veg_envelope.c")]
subprocess.run(["gcc", *flags, str(ROOT/"port/syxg_core.c"), str(ROOT/"port/render_native.c"),
                "-o", str(OUT/"render_native.exe")], check=True, cwd=ROOT, env=environment)
subprocess.run(["gcc", *flags, "-shared", str(ROOT/"port/syxg_core.c"),
                "-o", str(OUT/"syxg_core.dll")], check=True, cwd=ROOT, env=environment)
common = [str(ZIG), "cc", *flags, str(ROOT/"port/syxg_core.c")]
exports = ["sxg_bank_buffer", "sxg_wave_buffer", "sxg_bank_capacity", "sxg_wave_capacity", "sxg_init",
           "sxg_midi", "sxg_render", "sxg_output_buffer", "sxg_reset", "sxg_layer_count", "sxg_layer_info",
           "sxg_probe_oscillator8", "sxg_oscillator_output", "sxg_oscillator_position", "sxg_oscillator_fraction",
           "sxg_envelope_gain", "sxg_envelope_advance", "sxg_sysex_buffer", "sxg_sysex_capacity", "sxg_sysex",
           "sxg_set_master", "sxg_set_effects", "sxg_active_voices", "sxg_channel_info", "sxg_voice_envelope"]
subprocess.run(common+["--target=wasm32-freestanding", "-mbulk-memory", "-nostdlib", "-Wl,--no-entry", "-Wl,--export-memory",
                      "-Wl,-z,stack-size=1048576", "-Wl,--initial-memory=8388608", "-Wl,--max-memory=16777216",
                      *["-Wl,--export="+name for name in exports], "-o", str(OUT/"syxg_core.wasm")], check=True, cwd=ROOT, env=environment)
print("Built native renderer and build/syxg_core.wasm")
