#pragma once

#include "math/misc.hpp"
#include <utility>

namespace oh {
  namespace math {
    namespace geometry {

template<typename T>
struct Point2;

typedef Point2<int> Point2i;
typedef Point2<float> Point2f;
typedef Point2<double> Point2d;

template<typename T>
struct Point2 {
  Point2() : x(T()), y(T()) {}
  Point2(T _x, T _y) : x(_x), y(_y) {}

  Point2& operator-();
  Point2 operator+(const Point2& point) const;
  Point2 operator-(const Point2& point) const;
  Point2 operator*(T scalar) const;
  Point2 operator/(T scalar) const;

  Point2& operator+=(const Point2& point);
  Point2& operator-=(const Point2& point);
  Point2& operator*=(T scalar);
  Point2& operator/=(T scalar);

  bool operator==(const Point2& point) const;
  bool operator!=(const Point2& point) const;

  float PolarRadius() const;
  float PolarAngle() const;
  std::pair<float, float> PolarCoords() const;

  T x, y;
};

template<typename T>
std::pair<float, float> Point2<T>::PolarCoords() const
{
  return std::make_pair(PolarRadius(), PolarAngle());
}

template<typename T>
float Point2<T>::PolarAngle() const
{
  if (x > 0 && y >= 0) return atan(y/x);
  if (x > 0 && y < 0) return atan(y/x) + 2 * PI_F;
  if (x < 0) return atan(y/x) + PI_F;
  if (x == 0 && y > 0) return PI_F/2.0f;
  if (x == 0 && y < 0) return (3.0f * PI_F)/2.0f;
}

template<typename T>
float Point2<T>::PolarRadius() const
{
  return sqrt(x * x + y * y);
}

template<typename T>
Point2<T>& Point2<T>::operator/=(T scalar)
{
  x /= scalar;
  y /= scalar;
  return *this;
}

template<typename T>
Point2<T>& Point2<T>::operator*=(T scalar)
{
  x *= scalar;
  y *= scalar;
  return *this;
}

template<typename T>
Point2<T>& Point2<T>::operator-=(const Point2& point)
{
  x -= point.x;
  y -= point.y;
  return *this;
}

template<typename T>
Point2<T>& Point2<T>::operator+=(const Point2& point)
{
  x += point.x;
  y += point.y;
  return *this;
}

template<typename T>
bool Point2<T>::operator!=(const Point2& point) const
{
  return !(*this == point);
}

// need specialization for floating point numbers
template<typename T>
bool Point2<T>::operator==(const Point2& point) const
{
  return x == point.x && y == point.y;
}

template<typename T>
Point2<T> Point2<T>::operator/(T scalar) const
{
  return Point2<T>(x / scalar, y / scalar);
}

template<typename T>
Point2<T> Point2<T>::operator*(T scalar) const
{
  return Point2<T>(x * scalar, y * scalar);
}

template<typename T>
Point2<T> Point2<T>::operator-(const Point2& point) const
{
  return Point2<T>(x - point.x, y - point.y);
}

template<typename T>
Point2<T> Point2<T>::operator+(const Point2& point) const
{
  return Point2<T>(x + point.x, y + point.y);
}

template<typename T>
Point2<T>& Point2<T>::operator-()
{
  x = -x;
  y = -y;
  return *this;
}

}}}
// ~~ oh::math::geometry::Point2
