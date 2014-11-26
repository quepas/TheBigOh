#include "math/fibonacci.hpp"
#include <catch.hpp>

using oh::math::Fibonacci;
using oh::math::Fibonacci_;
using oh::math::FIBONACCI_SEQUENCE;
using oh::math::FIBONACCI_SIZE;

TEST_CASE("Generate fibonacci sequence") {
  SECTION("Fibonacci with tail-recursive algorithm") {
    for (unsigned idx = 0; idx < FIBONACCI_SIZE; ++idx) {
      REQUIRE(Fibonacci_(idx) == FIBONACCI_SEQUENCE[idx]);
    }
    REQUIRE(Fibonacci_(0) == 0);
    REQUIRE(Fibonacci_(1) == 1);
    REQUIRE(Fibonacci_(2) == 1);
  }

  SECTION("Fibonacci with iterative algorithm") {
    for (unsigned idx = 0; idx < FIBONACCI_SIZE; ++idx) {
      REQUIRE(Fibonacci(idx) == FIBONACCI_SEQUENCE[idx]);
    }
    REQUIRE(Fibonacci(0) == 0);
    REQUIRE(Fibonacci(1) == 1);
    REQUIRE(Fibonacci(2) == 1);
  }
}