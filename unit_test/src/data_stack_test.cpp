#include "data/stack.hpp"
#include <catch.hpp>

using oh::data::Stack;

TEST_CASE("Fixed-size stack operations") {
  SECTION("Basic stack operations") {
    Stack<int> stack(5);

    REQUIRE(stack.IsEmpty());
    REQUIRE(stack.Size() == 0);
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    REQUIRE(stack.Size() == 5);
    stack.Push(6);
    REQUIRE(stack.Size() == 5);
    REQUIRE(stack.Pop() == 5);
    REQUIRE(stack.Size() == 4);
    REQUIRE(stack.Pop() == 4);
    REQUIRE(stack.Size() == 3);
    stack.Push(7);
    REQUIRE(stack.Size() == 4);
    REQUIRE(stack.Pop() == 7);
    REQUIRE(stack.Pop() == 3);
    stack.Clear();
    REQUIRE(stack.Size() == 0);
    REQUIRE(stack.Pop() == 0);
  }
}
