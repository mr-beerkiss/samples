# Assembley

Code from here: https://www.tldp.org/HOWTO/Assembly-HOWTO/hello.html

Running 
```bash
# Run Debian Docker
docker run --rm -it -v "$(pwd):/opt/code" debian:jessie bash

# Install requirements
apt-get install -y build-essential nasm

# Create an object file for 64bit architecture, this creates an object (.o) file 
nasm -f elf64 hello.asm

# Use ld to create an executable program
ld hello.o -o hello

# run it (note we can run it directly because of the _start: procedure)
./hello
