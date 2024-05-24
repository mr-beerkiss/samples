import socket
import os

# Create a socket for the ALG interface
alg_socket = socket.socket(socket.AF_ALG, socket.SOCK_SEQPACKET, 0)

# Specify the algorithm type and name
# you can check the available algorithms in /proc/crypto
alg_type = 'hash'
alg_name = 'sha256'
alg_socket.bind((alg_type, alg_name))

# To perform a hash operation, we need a connection to the socket
alg_connection = alg_socket.accept()[0]

# Data to hash
data = b"Hello, this is a test for SHA-256 hashing!"

# Send data to the hashing algorithm via the connection
alg_connection.sendall(data)

# Read the hash result
hash_result = alg_connection.recv(32)  # SHA-256 produces a 32 byte digest

# Close the connection and the socket
alg_connection.close()
alg_socket.close()

# Print the hash result in hexadecimal format
print("SHA-256 hash:", hash_result.hex())
