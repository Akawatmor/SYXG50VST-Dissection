"""Reproduce VEG envelope fixtures from unchanged DLL calls on cloned voices."""
from pathlib import Path
import os,subprocess
ROOT=Path(__file__).resolve().parents[1]
compiler=Path(os.environ['WINDIR'])/'Microsoft.NET/Framework/v4.0.30319/csc.exe'
host=ROOT/'tools/VegOracle.exe'
subprocess.run([str(compiler),'/nologo','/platform:x86','/optimize+','/out:'+str(host),str(ROOT/'tools/ReferenceHost.cs'),str(ROOT/'tools/VegEnvelopeOracle.cs')],check=True)
env=os.environ.copy();env['SYXG_VEG_ENVELOPE']='1'
for rate in [44100,48000]:
    prefix=ROOT/('analysis/veg-envelope/veg-'+str(rate))
    with (ROOT/('build/veg-envelope-'+str(rate)+'.log')).open('w') as log:
        subprocess.run([str(host),str(ROOT/'dll/veg/syxg50.dll'),str(prefix),'note',str(rate),'128'],check=True,env=env,stdout=log,stderr=subprocess.STDOUT,cwd=ROOT)
