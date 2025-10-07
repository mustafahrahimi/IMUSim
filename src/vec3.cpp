#include "vec3.hpp"
#include <cassert>

Vec3 Vec3::operator+(const Vec3& o) const { return Vec3(x+o.x, y+o.y, z+o.z); }
Vec3 Vec3::operator-(const Vec3& o) const { return Vec3(x-o.x, y-o.y, z-o.z); }
Vec3 Vec3::operator*(double s) const { return Vec3(x*s, y*s, z*s); }
Vec3 Vec3::operator/(double s) const { assert(s != 0.0); return Vec3(x/s, y/s, z/s); }

Vec3& Vec3::operator+=(const Vec3& o) { x += o.x; y += o.y; z += o.z; return *this; }
Vec3& Vec3::operator-=(const Vec3& o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
Vec3& Vec3::operator*=(double s) { x *= s; y *= s; z *= s; return *this; }
Vec3& Vec3::operator/=(double s) { assert(s != 0.0); x /= s; y /= s; z /= s; return *this; }

double Vec3::norm() const { return std::sqrt(x*x + y*y + z*z); }
double Vec3::squared_norm() const { return x*x + y*y + z*z; }
Vec3 Vec3::normalized() const {
    double n = norm();
    if (n == 0.0) return Vec3(0,0,0);
    return (*this) / n;
}

double Vec3::dot(const Vec3& a, const Vec3& b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
Vec3 Vec3::cross(const Vec3& a, const Vec3& b) {
    return Vec3(
        a.y*b.z - a.z*b.y,
        a.z*b.x - a.x*b.z,
        a.x*b.y - a.y*b.x
    );
}

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}
