"""Serve the local synth, its WASM module and the two supplied bank files."""
from pathlib import Path
from http.server import ThreadingHTTPServer, SimpleHTTPRequestHandler
import argparse
import functools
import webbrowser

ROOT = Path(__file__).resolve().parents[1]


class Handler(SimpleHTTPRequestHandler):
    def translate_path(self, path):
        clean = path.split("?", 1)[0]
        aliases = {
            "/syxg_core.wasm": ROOT / "build/syxg_core.wasm",
            "/banks/sxgbin41.tbl": ROOT / "dll/legacy/sxgbin41.tbl",
            "/banks/Sxgwave4.tbl": ROOT / "dll/legacy/Sxgwave4.tbl",
        }
        if clean in aliases:
            return str(aliases[clean])
        return super().translate_path(path)

    def end_headers(self):
        self.send_header("Cache-Control", "no-cache")
        self.send_header("X-Content-Type-Options", "nosniff")
        self.send_header("Permissions-Policy", "midi=(self)")
        super().end_headers()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--port", type=int, default=8765)
    parser.add_argument("--open", action="store_true")
    args = parser.parse_args()
    handler = functools.partial(Handler, directory=str(ROOT / "web"))
    server = ThreadingHTTPServer(("127.0.0.1", args.port), handler)
    address = f"http://127.0.0.1:{server.server_port}/"
    print(address, flush=True)
    if args.open:
        webbrowser.open(address)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        server.server_close()


if __name__ == "__main__":
    main()
