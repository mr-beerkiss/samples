FROM python:3.9-slim-buster

# Install any necessary packages
RUN apt-get update && apt-get install -y \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy your Python script
COPY hash_script.py /hash_script.py

# Run your Python script
CMD ["python", "/hash_script.py"]
