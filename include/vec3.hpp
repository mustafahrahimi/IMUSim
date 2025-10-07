#pragma once

#include <cmath>
#include <ostream>

struct Vec3 {
    double x;
    double y;
    double z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    // basic ops
    Vec3 operator+(const Vec3& o) const;
    Vec3 operator-(const Vec3& o) const;
    Vec3 operator*(double s) const;
    Vec3 operator/(double s) const;

    // in-place
    Vec3& operator+=(const Vec3& o);
    Vec3& operator-=(const Vec3& o);
    Vec3& operator*=(double s);
    Vec3& operator/=(double s);

    double norm() const;
    double squared_norm() const; 
    Vec3 normalized() const;

    static double dot(const Vec3& a, const Vec3& b);
    static Vec3 cross(const Vec3& a, const Vec3& b);
};

std::ostream& operator<<(std::ostream& os, const Vec3& v);

