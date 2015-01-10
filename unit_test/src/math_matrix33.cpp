#include "math/matrix33.hpp"
#include <catch.hpp>

using oh::math::Matrix33i;

TEST_CASE("Basic usage of 3x3 matrix") {
  SECTION("Matrix creation") {
    Matrix33i a;
    REQUIRE(a.m11 == 0);
    REQUIRE(a.m12 == 0);
    REQUIRE(a.m13 == 0);
    REQUIRE(a.m21 == 0);
    REQUIRE(a.m22 == 0);
    REQUIRE(a.m23 == 0);
    REQUIRE(a.m31 == 0);
    REQUIRE(a.m32 == 0);
    REQUIRE(a.m33 == 0);
    Matrix33i b(6, 1, 1, 4, -2, 5, 2, 8, 7);
    REQUIRE(b.m11 == 6);
    REQUIRE(b.m12 == 1);
    REQUIRE(b.m13 == 1);
    REQUIRE(b.m21 == 4);
    REQUIRE(b.m22 == -2);
    REQUIRE(b.m23 == 5);
    REQUIRE(b.m31 == 2);
    REQUIRE(b.m32 == 8);
    REQUIRE(b.m33 == 7);
  }

  SECTION("Calculating matrix determinant") {
    Matrix33i a;
    REQUIRE(a.Det() == 0);
    Matrix33i b(6, 1, 1, 4, -2, 5, 2, 8, 7);
    REQUIRE(b.Det() == -306);
    Matrix33i c = Matrix33i::Diag(1, 2, 3);
    REQUIRE(c.Det() == 6);
  }
}
