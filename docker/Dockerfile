FROM ubuntu:22.04

RUN apt-get update && apt-get install -y build-essential cmake git

WORKDIR /workspace
COPY . .

# Build main program & tests
# When Cmake is run, it builds 2 binaries imusim & runTests inside the
# build module and these 2 binaries can be used to either run the main program
# or only the tests.
RUN mkdir -p build && cd build && cmake .. && cmake --build .

# Default entrypoint: run main executable
CMD ["./build/imusim"]
