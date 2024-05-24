import os
import socket
import sys

def main():
    if len(sys.argv) != 2:
        print("Usage: udp_client.py <content>")
        exit(1)

    content = sys.argv[1]
    target_host = os.getenv("HOST") or "127.0.0.1"
    target_port = int(os.getenv("PORT") or 9997)
    

    # create a socket object
    client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    # send some data
    client.sendto(content.encode("utf-8"), (target_host, target_port))

    # receive some data
    # second arg is `addr` assume that's for the server. Setting it to _ to remove warning
    data, _ = client.recvfrom(4096)

    print(data.decode())

    client.close()

if __name__ == "__main__":
    main()

