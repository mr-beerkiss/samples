import os
import socket
import sys

if __name__ == "__main__":
    body = ""
    if len(sys.argv) == 2:
        body = sys.argv[1]

    target_host = os.getenv("HOST") or "0.0.0.0" 
    target_port = int(os.getenv("PORT") or 80)

    # create a socket connection
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    print(f"connecting to {target_host} on port {target_port}")
    # connect the client
    client.connect((target_host, target_port))

    # send some data
    client.send(f"GET / HTTP/1.1\r\nHost: {target_host}\r\n\r\n{body}".encode("utf-8"))

    # receive some data
    response = client.recv(4096)

    print(response.decode())

    client.close()

    
