#!/usr/bin/env python3
"""Stream cameras to web browser - view on your computer
Run on R2D3 robot, view at http://172.20.10.5:8888
"""

from http.server import HTTPServer, BaseHTTPRequestHandler
import cv2
import threading
import time

PORT = 8888
cameras = {}
frames = {}
lock = threading.Lock()


class StreamHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path == '/':
            self.send_response(200)
            self.send_header('Content-type', 'text/html')
            self.end_headers()

            html = '''<!DOCTYPE html>
<html><head><title>R2D3 Cameras</title>
<style>
body { background: #1a1a1a; color: white; font-family: sans-serif; text-align: center; }
h1 { margin: 20px; }
.cameras { display: flex; flex-wrap: wrap; justify-content: center; gap: 20px; padding: 20px; }
.cam { background: #333; padding: 10px; border-radius: 8px; }
.cam img { max-width: 640px; border-radius: 4px; }
.cam h3 { margin: 10px 0; }
</style>
</head><body>
<h1>R2D3 Camera Feeds</h1>
<div class="cameras">
'''
            for idx in cameras.keys():
                html += f'<div class="cam"><h3>Camera {idx}</h3><img src="/cam/{idx}" /></div>'

            html += '''
</div>
<p>Auto-refreshing every second</p>
<script>setTimeout(() => location.reload(), 1000);</script>
</body></html>'''
            self.wfile.write(html.encode())

        elif self.path.startswith('/cam/'):
            try:
                idx = int(self.path.split('/')[-1])
                with lock:
                    if idx in frames and frames[idx] is not None:
                        _, jpeg = cv2.imencode('.jpg', frames[idx])
                        self.send_response(200)
                        self.send_header('Content-type', 'image/jpeg')
                        self.end_headers()
                        self.wfile.write(jpeg.tobytes())
                        return
            except:
                pass
            self.send_response(404)
            self.end_headers()
        else:
            self.send_response(404)
            self.end_headers()

    def log_message(self, format, *args):
        pass


def capture_loop():
    global frames
    while True:
        for idx, cap in cameras.items():
            ret, frame = cap.read()
            if ret:
                cv2.putText(frame, f'Camera {idx}', (10, 30),
                           cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
                with lock:
                    frames[idx] = frame
        time.sleep(0.1)


def main():
    print('=' * 60)
    print('R2D3 CAMERA STREAM')
    print('=' * 60)
    print('Searching for cameras...')

    for idx in range(10):
        cap = cv2.VideoCapture(idx)
        if cap.isOpened():
            ret, _ = cap.read()
            if ret:
                print(f'  Camera {idx}: FOUND')
                cameras[idx] = cap
                frames[idx] = None
            else:
                cap.release()

    if not cameras:
        print('No cameras found!')
        return

    print(f'\nFound {len(cameras)} camera(s)')
    print()
    print(f'>>> View in browser: http://172.20.10.5:{PORT}')
    print('Press Ctrl+C to stop')
    print('=' * 60)

    capture_thread = threading.Thread(target=capture_loop, daemon=True)
    capture_thread.start()

    server = HTTPServer(('0.0.0.0', PORT), StreamHandler)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print('\nStopping...')
    finally:
        for cap in cameras.values():
            cap.release()


if __name__ == '__main__':
    main()
