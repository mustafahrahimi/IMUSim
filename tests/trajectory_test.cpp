#include "trajectory.hpp"
#include <gtest/gtest.h>

TEST(TrajectoryTest, StepAndPosition) {
    Trajectory traj(0.1);
    Vec3 pos0 = traj.getPosition();
    traj.step();
    Vec3 pos1 = traj.getPosition();
    EXPECT_NE(pos0.x, pos1.x); 
}
