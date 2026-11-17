"""Create a local-use package from the supplied banks and built WASM."""
from pathlib import Path
import hashlib
import json
import zipfile

ROOT = Path(__file__).resolve().parents[1]
target = ROOT / 'build/syxg50-web.zip'
files = [(path, path.relative_to(ROOT).as_posix()) for path in sorted((ROOT/'web').rglob('*')) if path.is_file() and (path.suffix != '.bmp') and (path.parent.name != 'assets' or path.name == 'resource-111.png')]
for name in ['build/syxg_core.wasm','tools/serve_web.py','Start S-YXG50.cmd','port/README.md','analysis/PHASE_6_7_REPORT.md']:
    files.append((ROOT/name,'README.md' if name=='port/README.md' else name))
for name in ['sxgbin41.tbl','Sxgwave4.tbl']:
    files.append((ROOT/'dll/legacy'/name,'dll/legacy/'+name))
manifest={name:hashlib.sha256(path.read_bytes()).hexdigest() for path,name in files}
with zipfile.ZipFile(target,'w',zipfile.ZIP_DEFLATED,compresslevel=9) as archive:
    for path,name in files: archive.write(path,name)
    archive.writestr('SHA256.json',json.dumps(manifest,indent=2))
with zipfile.ZipFile(target) as archive:
    assert archive.testzip() is None
    assert all(hashlib.sha256(archive.read(name)).hexdigest()==digest for name,digest in manifest.items())
digest=hashlib.sha256(target.read_bytes()).hexdigest()
target.with_suffix('.zip.sha256').write_text(digest+'  '+target.name+'\n')
print(json.dumps({'archive':str(target),'bytes':target.stat().st_size,'files':len(files)+1,'sha256':digest},indent=2))
