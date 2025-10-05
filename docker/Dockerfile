FROM ubuntu:22.04

RUN apt-get update && apt-get install -y build-essential cmake git

WORKDIR /workspace
COPY . .

RUN mkdir -p build && cd build && cmake .. && cmake --build .

ENTRYPOINT ["./build/imusim"]
