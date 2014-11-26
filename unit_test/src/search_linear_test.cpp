#include "search/linear.hpp"
#include "data/list.hpp"
#include <catch.hpp>

using oh::data::List;
using oh::search::LinearSearch;

TEST_CASE("Simple linear search") {
  SECTION("Linear search on static array") {
    int array[] = {2, 32, 3, -12, 0, 341, 1, 1, 1, 3155135};

    unsigned position;
    REQUIRE(LinearSearch(array, -12, position));
    REQUIRE(position == 3);
    REQUIRE(LinearSearch(array, 888, position) == false);
    REQUIRE(LinearSearch(array, 3155135, position));
    REQUIRE(position == 9);
    REQUIRE(LinearSearch(array, 1, position));
    REQUIRE(position == 6);

    int singleton[] = { -1 };
    REQUIRE(LinearSearch(singleton, -1, position));
    REQUIRE(position == 0);
    REQUIRE(LinearSearch(singleton, 0, position) == false);
  }

  SECTION("Linear search on list") {
    List<int> list;

    unsigned position;
    REQUIRE(LinearSearch(list, 0, position) == false);
    list.Append(2);
    list.Append(32);
    list.Append(3);
    list.Append(-12);
    list.Append(0);
    list.Append(341);
    list.Append(1);
    list.Append(1);
    list.Append(1);
    list.Append(3155135);
    REQUIRE(list.Size() == 10);
    REQUIRE(list.IsEmpty() == false);
    REQUIRE(LinearSearch(list, -12, position));
    REQUIRE(LinearSearch(list, -12, position));
    REQUIRE(position == 3);
    REQUIRE(LinearSearch(list, 888, position) == false);
    REQUIRE(LinearSearch(list, 3155135, position));
    REQUIRE(position == 9);
    REQUIRE(LinearSearch(list, 1, position));
    REQUIRE(position == 6);
  }
}