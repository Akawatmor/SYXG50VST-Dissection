"""Capture bank memory, voice state and original oscillator fixtures from the supplied DLL."""
from pathlib import Path
import os
import subprocess

ROOT = Path(__file__).resolve().parents[1]
compiler = Path(os.environ.get("WINDIR", r"C:\Windows"))/"Microsoft.NET/Framework/v4.0.30319/csc.exe"
host = ROOT/"tools/ReferenceHostAnalysis.exe"
subprocess.run([str(compiler), "/nologo", "/platform:x86", "/optimize+", "/out:"+str(host),
                str(ROOT/"tools/ReferenceHost.cs")], check=True, cwd=ROOT)
environment = os.environ.copy()
environment["SYXG_ANALYSIS_DUMP"] = "1"
result = subprocess.run([str(host), str(ROOT/"dll/legacy/S-YXG50.dll"),
                         str(ROOT/"analysis/step3/legacy-dump"), "note"],
                        env=environment, capture_output=True, text=True, timeout=30, cwd=ROOT)
print(result.stdout[-1500:])
if result.returncode:
    raise SystemExit("Original DLL capture failed\n"+result.stderr)
