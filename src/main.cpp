#include <iostream>
#include "vec3.hpp"
#include "trajectory.hpp"
#include "imu_sensor.hpp"
#include "kalman_filter.hpp"

int main() {
    Trajectory traj(0.01);
    IMUSensor imu(0.02, 0.01, 0.01);
    KalmanFilter kf(0.01, 0.001, 0.01);

    for (int i = 0; i < 50; ++i) {
        Vec3 true_acc = traj.getAcceleration();
        Vec3 noisy_acc = imu.readAcceleration(true_acc);
        kf.predict(noisy_acc);

        Vec3 true_pos = traj.getPosition();
        kf.update(true_pos); 

        std::cout << "t=" << i*0.01
                  << " true_pos=" << true_pos
                  << " est_pos=" << kf.getPosition()
                  << "\n";

        traj.step();
    }

    return 0;
}

