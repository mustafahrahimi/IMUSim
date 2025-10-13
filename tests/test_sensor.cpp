#include "imu_sensor.hpp"
#include <gtest/gtest.h>

TEST(IMUSensorTest, AccelNoise) {
    IMUSensor imu(0.01, 0.01, 0.01);
    Vec3 true_acc(1,1,1);
    Vec3 noisy = imu.readAcceleration(true_acc);
    EXPECT_NE(noisy.x, true_acc.x);
}