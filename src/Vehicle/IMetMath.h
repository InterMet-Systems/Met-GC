#ifndef IMETMATH_H
#define IMETMATH_H

namespace IMetMath {

inline constexpr double pi = 3.14159265358979323846;
inline constexpr double absoluteZeroK = 0.;
inline constexpr double absoluteZeroC = -273.15;
inline constexpr double absoluteZeroF = -459.67;
inline constexpr double absoluteZeroR = 0.;

enum class Result{
    _SUCCESS,
    _FAILURE,
    _INPUT_NAN,
    _INPUT_INF,
    _OUTPUT_NAN,
    _OUTPUT_INF,
    _INPUT_EXCEEDS_RANGE,
    _OUTPUT_EXCEEDS_RANGE,
};

struct SResult{
    Result result;
    double value;
};

constexpr SResult CelsiusToKelvin(const double& celsius) {
    if (std::isnan(celsius))                return  { Result::_INPUT_NAN, 0.0 };
    if (std::isinf(celsius))                return  { Result::_INPUT_INF, 0.0 };
    const double kelvin = celsius + 273.15;
    if (std::isnan(kelvin))                 return  { Result::_OUTPUT_NAN, 0.0 };
    if (std::isinf(kelvin))                 return  { Result::_OUTPUT_INF, 0.0 };
    if (celsius < absoluteZeroC)            return  { Result::_INPUT_EXCEEDS_RANGE, kelvin };
    if (kelvin < absoluteZeroK)             return  { Result::_OUTPUT_EXCEEDS_RANGE, kelvin };

    return { Result::_SUCCESS, kelvin };
}

constexpr SResult KelvinToCelsius(const double& kelvin) {
    if (std::isnan(kelvin))                 return  { Result::_INPUT_NAN, 0.0 };
    if (std::isinf(kelvin))                 return  { Result::_INPUT_INF, 0.0 };
    const double celsius = kelvin - 273.15;
    if (std::isnan(celsius))                return  { Result::_OUTPUT_NAN, 0.0 };
    if (std::isinf(celsius))                return  { Result::_OUTPUT_INF, 0.0 };
    if (kelvin < absoluteZeroK)             return  { Result::_INPUT_EXCEEDS_RANGE, celsius };
    if (celsius < absoluteZeroC)            return  { Result::_OUTPUT_EXCEEDS_RANGE, celsius };

    return { Result::_SUCCESS, celsius };
}

constexpr SResult DegreesToRadians(const double& degrees){
    if (std::isnan(degrees))                return  { Result::_INPUT_NAN, 0.0 };
    if (std::isinf(degrees))                return  { Result::_INPUT_INF, 0.0 };
    const double radians = degrees * (pi / 180.);
    if (std::isnan(radians))                return  { Result::_OUTPUT_NAN, 0.0 };
    if (std::isinf(radians))                return  { Result::_OUTPUT_INF, 0.0 };
    if (degrees < 0. || degrees > 360.)     return  { Result::_INPUT_EXCEEDS_RANGE, radians };
    if (radians < 0. || radians > 2 * pi)   return  { Result::_OUTPUT_EXCEEDS_RANGE, radians };

    return { Result::_SUCCESS, radians};
}

constexpr SResult RadiansToDegrees(const double& radians){
    if (std::isnan(radians))                return  { Result::_INPUT_NAN, 0.0 };
    if (std::isinf(radians))                return  { Result::_INPUT_INF, 0.0 };
    const double degrees = radians * (180. / pi);
    if (std::isnan(degrees))                return  { Result::_OUTPUT_NAN, 0.0 };
    if (std::isinf(degrees))                return  { Result::_OUTPUT_INF, 0.0 };
    if (radians < 0. || radians > 2 * pi)   return  { Result::_INPUT_EXCEEDS_RANGE, degrees };
    if (degrees < 0. || degrees > 360.)     return  { Result::_OUTPUT_EXCEEDS_RANGE, degrees };

    return { Result::_SUCCESS, degrees };
}

}


#endif // IMETMATH_H
