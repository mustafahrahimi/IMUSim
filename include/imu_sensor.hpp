#pragma once

#include "vec3.hpp"
#include "trajectory.hpp"

class IMUSensor {
    public:
        IMUSensor(double accel_noise_std, double gyro_noise_std, double dt);

        Vec3 readAcceleration(const Vec3& true_acc);

        Vec3 readGyro(const Vec3& true_vel);

    private:
        double accel_noise_std;
        double gyro_noise_std;
        double dt;

        Vec3 gyro_bias; 
        double gaussianNoise(double stddev);
};
