#include <iostream>
#include "vec3.hpp"

int main() {
    Vec3 a(1.0, 2.0, 3.0);
    Vec3 b(4.0, 5.0, 6.0);

    Vec3 c = a + b;
    Vec3 d = Vec3::cross(a, b);
    double dp = Vec3::dot(a, b);
    double norm_a = a.norm();
    double sqrd_norm_a = a.squared_norm();

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << c << std::endl;
    std::cout << "a x b: " << d << std::endl;
    std::cout << "a . b: " << dp << std::endl;
    std::cout << "|a|: " << norm_a << std::endl;
    std::cout << "|a|^2: " << sqrd_norm_a << std::endl;

    return 0;
}

