#include <iostream>
#include "vec3.hpp"
#include "trajectory.hpp"
#include "imu_sensor.hpp"
#include "kalman_filter.hpp"
#include "logger.hpp"

int main() {
    double dt = 0.01;
    Trajectory traj(dt);
    IMUSensor imu(0.05, 0.03, 0.02);
    KalmanFilter kf(dt, 0.001, 0.01);
    Logger logger("data/outputs/simulation.csv");

    for (int i = 0; i < 1000; ++i) {
        double t = i * dt;

        Vec3 true_pos = traj.getPosition();
        Vec3 true_acc = traj.getAcceleration();
        Vec3 noisy_acc = imu.readAcceleration(true_acc);

        kf.predict(noisy_acc);
        kf.update(true_pos);

        logger.write(t, true_pos, noisy_acc, kf.getPosition());

        traj.step();
    }
    
    std::cout << "Simulation complete. Results saved to simulation.csv\n";
    return 0;
}

