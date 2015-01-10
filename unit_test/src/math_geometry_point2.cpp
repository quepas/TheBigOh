#include "math/geometry/point2.hpp"
#include <catch.hpp>

using oh::math::geometry::Point2i;

TEST_CASE("Simple point test-cases") {
  SECTION("Point creation and comparision operators") {
    Point2i a;
    REQUIRE(a == Point2i(0, 0));
    Point2i b(3, -2);
    REQUIRE(b.x == 3);
    REQUIRE(b.y ==-2);
    REQUIRE(b == Point2i(3, -2));
    REQUIRE(b != Point2i(3, 2));
    Point2i c(b);
    REQUIRE(c.x == 3);
    REQUIRE(c.y ==-2);
    REQUIRE(b == c);
  }

  SECTION("Basic operations") {
    Point2i a;
    REQUIRE((a * 3) == Point2i(0, 0));
    REQUIRE((a * 0) == Point2i(0, 0));
    REQUIRE((a * -3) == Point2i(0, 0));
    REQUIRE((a * 1) == a);
    REQUIRE((-a) == a);
    Point2i b(3, -2);
    REQUIRE((b * 0) == a);
    REQUIRE((b * 1) == b);
    REQUIRE((b * 2) == Point2i(6, -4));
    REQUIRE((b * -2) == Point2i(-6, 4));
    REQUIRE((-b) == Point2i(-3, 2));
  }

  SECTION("Assignment operations") {
    Point2i a;
    a*=2;
    REQUIRE(a == Point2i(0,0));
    a+=Point2i(1, 1);
    REQUIRE(a == Point2i(1, 1));
    a*=9;
    REQUIRE(a == Point2i(9, 9));
    a/=3;
    REQUIRE(a == Point2i(3, 3));
    a-=Point2i(3, 3);
    REQUIRE(a == Point2i());
  }

}
