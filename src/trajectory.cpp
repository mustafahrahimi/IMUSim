#include "trajectory.hpp"
#include <cmath>

Trajectory::Trajectory(double dt_) : t(0.0), dt(dt_) {}

Vec3 Trajectory::getPosition() const {
    return Vec3(std::sin(t), std::cos(t), 0.1 * t);
}

Vec3 Trajectory::getVelocity() const {
    return Vec3(std::cos(t), -std::sin(t), 0.1);
}

Vec3 Trajectory::getAcceleration() const {
    return Vec3(-std::sin(t), -std::cos(t), 0.0);
}

void Trajectory::step() {
    t += dt;
}
