# IMUSim

IMUSim is a hardware-free IMU simulation and sensor-fusion engine written in C++.  
It models realistic accelerometer and gyro noise and applies a Kalman Filter to estimate motion.

## Build

Using CMake:
```bash
mkdir build
cd build
cmake ..
cmake --build .
./imusim

