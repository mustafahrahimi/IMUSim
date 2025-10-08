#pragma once

#include "vec3.hpp"

class KalmanFilter {
public:
    KalmanFilter(double dt, double process_noise, double measurement_noise);

    // Predict state forward
    void predict(const Vec3& accel);

    // Correct with measured position
    void update(const Vec3& measured_pos);

    Vec3 getPosition() const;
    Vec3 getVelocity() const;

private:
    double dt;
    double q; // process noise
    double r; // measurement noise

    Vec3 x;   // estimated position
    Vec3 v;   // estimated velocity
    Vec3 p;   // estimation uncertainty
};
