#include "logger.hpp"

Logger::Logger(const std::string& filename) {
    file.open(filename);
    file << "t,true_x,true_y,true_z,noisy_ax,noisy_ay,noisy_az,est_x,est_y,est_z\n";
}

Logger::~Logger() {
    if (file.is_open()) file.close();
}

void Logger::write(double t, const Vec3& true_pos, const Vec3& noisy_acc, const Vec3& est_pos) {
    file << t << ","
         << true_pos.x << "," << true_pos.y << "," << true_pos.z << ","
         << noisy_acc.x << "," << noisy_acc.y << "," << noisy_acc.z << ","
         << est_pos.x << "," << est_pos.y << "," << est_pos.z
         << "\n";
}
