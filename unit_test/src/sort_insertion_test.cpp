#include "sort/exchange.hpp"
#include <catch.hpp>

using oh::sort::ExchangeSort;

TEST_CASE("Exchange sorting") {
  SECTION("Basic exchange sort test") {
    const int SIZE = 11;
    int sorted[SIZE] = { -14, -1, 0, 1, 34, 53, 88, 90, 100, 123, 13551 };
    int sorted_repeat[SIZE] = { -14, -1, 0, 1, 53, 53, 88, 90, 123, 123, 13551 };

    int ascending[SIZE] = { -14, -1, 0, 1, 34, 53, 88, 90, 100, 123, 13551 };
    ExchangeSort(ascending);
    for (unsigned idx = 0; idx < SIZE; ++idx) {
      REQUIRE(sorted[idx] == ascending[idx]);
    }

    int none_descending[SIZE] = { -14, -1, 0, 1, 53, 53, 88, 90, 123, 123, 13551 };
    ExchangeSort(none_descending);
    for (unsigned idx = 0; idx < SIZE; ++idx) {
      REQUIRE(sorted_repeat[idx] == none_descending[idx]);
    }

    int descending[SIZE] = { 13551, 123, 100, 90, 88, 53, 34, 1, 0, -1, -14 };
    ExchangeSort(descending);
    for (unsigned idx = 0; idx < SIZE; ++idx) {
      REQUIRE(sorted[idx] == descending[idx]);
    }

    int none_ascending[SIZE] = { 13551, 123, 123, 90, 88, 53, 53, 1, 0, -1, -14 };
    ExchangeSort(none_ascending);
    for (unsigned idx = 0; idx < SIZE; ++idx) {
      REQUIRE(sorted_repeat[idx] == none_ascending[idx]);
    }

    int singleton [] = { 0 };
    ExchangeSort(singleton);
    REQUIRE(singleton[0] == 0);
  }
}