#pragma once

namespace oh {
  namespace math {

template<typename T>
struct Matrix33;

typedef Matrix33<int> Matrix33i;
typedef Matrix33<float> Matrix33f;
typedef Matrix33<double> Matrix33d;

template<typename T>
struct Matrix33 {
  Matrix33()
    : m11(T()), m12(T()), m13(T()),
      m21(T()), m22(T()), m23(T()),
      m31(T()), m32(T()), m33(T()) {}
  Matrix33(T _11, T _12, T _13,
           T _21, T _22, T _23,
           T _31, T _32, T _33)
    : m11(_11), m12(_12), m13(_13),
      m21(_21), m22(_22), m23(_23),
      m31(_31), m32(_32), m33(_33) {}

  T m11, m12, m13, m21, m22, m23, m31, m32, m33;

  T Det() {
    return m11 * m22 * m33 + m12 * m23 * m31 + m13 * m21 * m32 -
      m13 * m22 * m31 - m11 * m23 * m32 - m12 * m21 * m33;
  }

  static Matrix33 Diag(T _1, T _2, T _3);
};

template<typename T>
Matrix33<T> Matrix33<T>::Diag(T _1, T _2, T _3)
{
  return Matrix33<T>(_1, T(), T(),
                     T(), _2, T(),
                     T(), T(), _3);
}

}}
// ~~ oh::math::Matrix33
