#ifndef IMETMATH_H
#define IMETMATH_H

#include <algorithm>

namespace IMetMath {

inline constexpr double pi = 3.14159265358979323846;

constexpr double toRadians(double degrees) {
    return std::clamp((degrees * (pi / 180.)), 0., 2. * pi);
}

constexpr double toDegrees(double radians) {
    return std::clamp((radians * (180. / pi)), 0., 360.);
}

}


#endif // IMETMATH_H
