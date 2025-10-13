#include "vec3.hpp"
#include <gtest/gtest.h>

TEST(Vec3Test, Addition) {
    Vec3 a(1,2,3);
    Vec3 b(4,5,6);
    Vec3 c = a + b;
    EXPECT_DOUBLE_EQ(c.x, 5);
    EXPECT_DOUBLE_EQ(c.y, 7);
    EXPECT_DOUBLE_EQ(c.z, 9);
}

TEST(Vec3Test, ScalarMultiply) {
    Vec3 a(1,2,3);
    Vec3 c = a * 2.0;
    EXPECT_DOUBLE_EQ(c.x, 2);
    EXPECT_DOUBLE_EQ(c.y, 4);
    EXPECT_DOUBLE_EQ(c.z, 6);
}

TEST(Vec3Test, DotProduct) {
    Vec3 a(1,2,3), b(4,5,6);
    double dot = Vec3::dot(a, b);
    EXPECT_DOUBLE_EQ(dot, 1*4 + 2*5 + 3*6);
}

TEST(Vec3Test, Norm) {
    Vec3 a(3,4,0);
    EXPECT_DOUBLE_EQ(a.norm(), 5);
}

TEST(Vec3Test, Normalize) {
    Vec3 a(3,0,4);
    Vec3 n = a.normalized();
    double len = n.norm();
    EXPECT_NEAR(len, 1.0, 1e-9);
}
