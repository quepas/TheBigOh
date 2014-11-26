#include "data/list.hpp"
#include <catch.hpp>

using oh::data::List;

TEST_CASE("Dynamic single-linked list operations") {
  SECTION("Basic list operations") {
    List<int> list;

    REQUIRE_THROWS(list.Head());
    REQUIRE_THROWS(list.Tail());
    REQUIRE(list.IsEmpty());
    REQUIRE(list.Size() == 0);
    list.Append(4);
    REQUIRE(list.Head() == 4);
    auto tail = list.Tail();
    REQUIRE(tail.IsEmpty());
    REQUIRE(tail.Size() == 0);
    REQUIRE(list.IsEmpty() == false);
    REQUIRE(list.Size() == 1);
    list.Append(3);
    list.Append(2);
    list.Append(1);
    REQUIRE(list.IsEmpty() == false);
    REQUIRE(list.Size() == 4);
    REQUIRE(list.Head() == 4);
    tail = list.Tail();
    REQUIRE(tail.IsEmpty() == false);
    REQUIRE(tail.Size() == 3);
    REQUIRE(tail.Head() == 3);
    tail = tail.Tail();
    REQUIRE(tail.IsEmpty() == false);
    REQUIRE(tail.Size() == 2);
    REQUIRE(tail.Head() == 2);
    tail = tail.Tail();
    REQUIRE(tail.IsEmpty() == false);
    REQUIRE(tail.Size() == 1);
    REQUIRE(tail.Head() == 1);
    tail = tail.Tail();
    REQUIRE(tail.IsEmpty());
    REQUIRE(tail.Size() == 0);
    REQUIRE_THROWS(tail.Head());
    REQUIRE_THROWS(tail.Tail());
  }
}