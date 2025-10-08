#include "kalman_filter.hpp"
#include "vec3.hpp"

KalmanFilter::KalmanFilter(double dt_, double process_noise, double measurement_noise)
    : dt(dt_), q(process_noise), r(measurement_noise), x(0,0,0), v(0,0,0), p(1,1,1) {}

void KalmanFilter::predict(const Vec3& accel) {
    // Predict next state using simple constant acceleration model
    x += v * dt + accel * (0.5 * dt * dt);
    v += accel * dt;
    p += Vec3(q, q, q); // increase uncertainty
}

void KalmanFilter::update(const Vec3& measured_pos) {
    Vec3 K = p.cwiseDivide(p + Vec3(r, r, r)); 
    
    x += K.cwiseMultiply(measured_pos - x);
    p = (Vec3(1,1,1) - K).cwiseMultiply(p);
}

Vec3 KalmanFilter::getPosition() const { return x; }
Vec3 KalmanFilter::getVelocity() const { return v; }
