#include "imu_sensor.hpp"
#include <random>

static std::mt19937 rng(42);  
static std::normal_distribution<double> normal(0.0, 1.0);

IMUSensor::IMUSensor(double accel_std, double gyro_std, double dt_)
    : accel_noise_std(accel_std), gyro_noise_std(gyro_std), dt(dt_) {
    gyro_bias = Vec3(0.01, -0.02, 0.005); 
}

double IMUSensor::gaussianNoise(double stddev) {
    return normal(rng) * stddev;
}

Vec3 IMUSensor::readAcceleration(const Vec3& true_acc) {
    return true_acc + Vec3(
        gaussianNoise(accel_noise_std),
        gaussianNoise(accel_noise_std),
        gaussianNoise(accel_noise_std)
    );
}

Vec3 IMUSensor::readGyro(const Vec3& true_vel) {
    return true_vel + gyro_bias + Vec3(
        gaussianNoise(gyro_noise_std),
        gaussianNoise(gyro_noise_std),
        gaussianNoise(gyro_noise_std)
    );
}
