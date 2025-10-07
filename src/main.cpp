#include <iostream>
#include "vec3.hpp"
#include "trajectory.hpp"

int main() {
    Trajectory traj(0.1);

    for (int i = 0; i < 5; ++i) {
        std::cout << "=== Time Step " << i << " ===\n";
        Vec3 pos = traj.getPosition();
        Vec3 vel = traj.getVelocity();
        Vec3 acc = traj.getAcceleration();

        std::cout << "  Time step " << i << ":\n";
        std::cout << "  Position: (" << pos.x << ", " << pos.y << ", " << pos.z << ")\n";
        std::cout << "  Velocity: (" << vel.x << ", " << vel.y << ", " << vel.z << ")\n";
        std::cout << "  Acceleration: (" << acc.x << ", " << acc.y << ", " << acc.z << ")\n";

        traj.step();
    }

    return 0;
}

