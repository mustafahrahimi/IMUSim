#pragma once
#include "vec3.hpp"

class Trajectory {
    public:
        Trajectory(double dt);

        Vec3 getPosition() const;

        Vec3 getVelocity() const;

        Vec3 getAcceleration() const;

        void step();

    private:
        double t;      
        double dt;     
};
