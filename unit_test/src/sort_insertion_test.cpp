#include "sort/insertion.hpp"
#include <catch.hpp>

using oh::sort::InsertionSort;

TEST_CASE("Insertion sorting") {
  SECTION("Basic insertion sort test") {
    const int SIZE = 11;
    int sorted[SIZE] = { -14, -1, 0, 1, 34, 53, 88, 90, 100, 123, 13551 };
    int sorted_repeat[SIZE] = { -14, -1, 0, 1, 53, 53, 88, 90, 123, 123, 13551 };

    int ascending[SIZE] = { -14, -1, 0, 1, 34, 53, 88, 90, 100, 123, 13551 };
    InsertionSort(ascending);
    for (unsigned idx = 0; idx < SIZE; ++idx) {
      REQUIRE(sorted[idx] == ascending[idx]);
    }

    int none_descending[SIZE] = { -14, -1, 0, 1, 53, 53, 88, 90, 123, 123, 13551 };
    InsertionSort(none_descending);
    for (unsigned idx = 0; idx < SIZE; ++idx) {
      REQUIRE(sorted_repeat[idx] == none_descending[idx]);
    }

    int descending[SIZE] = { 13551, 123, 100, 90, 88, 53, 34, 1, 0, -1, -14 };
    InsertionSort(descending);
    for (unsigned idx = 0; idx < SIZE; ++idx) {
      REQUIRE(sorted[idx] == descending[idx]);
    }

    int none_ascending[SIZE] = { 13551, 123, 123, 90, 88, 53, 53, 1, 0, -1, -14 };
    InsertionSort(none_ascending);
    for (unsigned idx = 0; idx < SIZE; ++idx) {
      REQUIRE(sorted_repeat[idx] == none_ascending[idx]);
    }

    int singleton [] = { 0 };
    InsertionSort(singleton);
    REQUIRE(singleton[0] == 0);
  }
}