#ifndef IMETMATH_H
#define IMETMATH_H

#include <algorithm>

namespace IMetMath {

inline constexpr double pi = 3.14159265358979323846;

enum class Result{
    _SUCCESS,
    _FAILURE,
    _NAN,
    _INF,
    _EXCEEDS_RANGE,
};

struct SResult{
    Result result;
    double value;
};

constexpr double toRadians(double degrees) {
    return std::clamp((degrees * (pi / 180.)), 0., 2. * pi);
}

constexpr double toDegrees(double radians) {
    return std::clamp((radians * (180. / pi)), 0., 360.);
}

constexpr double toCelsius(double kelvin) {
    /* What if kelvin is negative? That's clearly a garbage value, but in some math context perhaps one wants to have that?
     * Should we address out of bounds values here, or in the calling context? Same kind of applies to the above functions. */
    return kelvin - 273.15;
}

/* new approach */
constexpr SResult DegreesToRadians(const double& degrees){
    double r = degrees * (pi / 180.);
    if (std::isnan(r)) return { Result::_NAN, r };
    if (std::isinf(r)) return { Result::_INF, r };
    if (r < 0. || r > 2 * pi) return { Result::_EXCEEDS_RANGE, r };
    return { Result::_SUCCESS, r};
}

}


#endif // IMETMATH_H
