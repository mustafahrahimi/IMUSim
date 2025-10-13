#include "kalman_filter.hpp"
#include <gtest/gtest.h>

TEST(KalmanFilterTest, PredictUpdate) {
    KalmanFilter kf(0.01, 0.001, 0.01);
    Vec3 accel(0.1,0.0,0.0);
    kf.predict(accel);
    Vec3 meas(0.001,0,0);
    kf.update(meas);
    Vec3 est = kf.getPosition();
    EXPECT_NEAR(est.x, 0.001, 0.1);
}
