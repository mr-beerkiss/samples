FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
	python3 nmap iputils-ping dnsutils \
	netcat-traditional procps

ENTRYPOINT ["bash"]

