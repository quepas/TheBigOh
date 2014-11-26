#include "helper/manipulate.hpp"
#include <catch.hpp>

using oh::helper::Swap;
using oh::helper::ExclusiveAssign;

TEST_CASE("Manipulation functions") {
  SECTION("Simple variables swapping") {
    int a = 5;
    int b = 3;
    REQUIRE(a == 5);
    REQUIRE(b == 3);
    Swap(a, b);
    REQUIRE(a == 3);
    REQUIRE(b == 5);

    int c = 0;
    REQUIRE(c == 0);
    Swap(c, c);
    REQUIRE(c == 0);

    int e = -1, f = -1;
    REQUIRE(e == -1);
    REQUIRE(f == -1);
    Swap(e, f);
    REQUIRE(e == -1);
    REQUIRE(f == -1);
  }

  SECTION("Exclusive assign in action") {
    int a = 3;
    int b = 5;
    REQUIRE(a == 3);
    REQUIRE(b == 5);
    ExclusiveAssign(a, b, b, a + b);
    REQUIRE(a == 5);
    REQUIRE(b == 8);
    ExclusiveAssign(a, 0, b, a + b);
    REQUIRE(a == 0);
    REQUIRE(b == 13);
  }
}