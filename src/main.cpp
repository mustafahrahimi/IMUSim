#include <iostream>
#include "vec3.hpp"
#include "trajectory.hpp"
#include "imu_sensor.hpp"

int main() {
    Trajectory traj(0.01);
    IMUSensor imu(0.01, 0.005, 0.01);

    for (int i = 0; i < 5; ++i) {
        Vec3 acc = traj.getAcceleration();
        Vec3 vel = traj.getVelocity();

        Vec3 noisy_acc = imu.readAcceleration(acc);
        Vec3 noisy_gyro = imu.readGyro(vel);

        std::cout << "t=" << i*0.01
                  << " true_acc=" << acc
                  << " noisy_acc=" << noisy_acc
                  << " noisy_gyro=" << noisy_gyro << "\n";

        traj.step();
    }

    return 0;
}

