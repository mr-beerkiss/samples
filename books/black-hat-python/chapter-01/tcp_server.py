import os
import socket
import threading

def main():
    IP = os.getenv("HOST") or "0.0.0.0"
    PORT = int(os.getenv("PORT") or 9998)

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((IP, PORT))
    
    server.listen(5)

    print(f"[*] Listening on {IP}:{PORT}")

    while True:
        client, addr = server.accept()
        print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")
        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()

def handle_client(client_socket):
    with client_socket as sock:
        buf_size = 4096
        data = bytearray()
        while True:
            # FIXME this kinda works but if recv gets 0 it seems to block until the 
            # client hangs up. 
            buf = sock.recv(buf_size)
            data.extend(buf)
            bytes_read = len(buf)
            print(f"[*] Bytes read: {bytes_read}")
            if len(buf) < buf_size:
                break

        print(f"[*] Received: {data.decode('utf-8')}")
        sock.send(b"ACK")

if __name__ == "__main__":
    main()

