#pragma once

#include <fstream>
#include <string>
#include "vec3.hpp"

class Logger {
    public:
        Logger(const std::string& filename);
        ~Logger();
        void write(double t, const Vec3& true_pos, const Vec3& noisy_acc, const Vec3& est_pos);

    private:
        std::ofstream file; 
};
