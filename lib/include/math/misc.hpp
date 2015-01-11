#pragma once

#include <cmath>
#include <limits>

namespace oh {
  namespace math {

const float PI_F = 3.14159265358979f;

inline bool IsEqual(float x, float y)
{
  return std::abs(x - y) <= std::numeric_limits<float>::epsilon() * std::abs(x);
}

template<typename T>
inline T min(T a, T b) {
  return a < b ? a : b;
}

template<typename T>
inline T max(T a, T b) {
  return a > b ? a : b;
}

}}
// ~~ oh::math::
