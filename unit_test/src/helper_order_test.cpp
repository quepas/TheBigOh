#include "helper/order.hpp"
#include <catch.hpp>

using oh::helper::InAscendingOrder;
using oh::helper::InNonAscendingOrder;
using oh::helper::InDescendingOrder;
using oh::helper::InNonDescendingOrder;

TEST_CASE("Various ordering tests") {
  SECTION("Asc/desc order tests") {
    int ascending [] = { -14, -1, 0, 1, 34, 53, 88, 90, 100, 123, 13551 };
    REQUIRE(InAscendingOrder(ascending));
    REQUIRE(InNonAscendingOrder(ascending) == false);
    REQUIRE(InDescendingOrder(ascending) == false);
    REQUIRE(InNonDescendingOrder(ascending));

    int none_descending [] = { -14, -1, 0, 1, 53, 53, 88, 90, 123, 123, 13551 };
    REQUIRE(InAscendingOrder(none_descending) == false);
    REQUIRE(InNonAscendingOrder(none_descending) == false);
    REQUIRE(InDescendingOrder(none_descending) == false);
    REQUIRE(InNonDescendingOrder(none_descending));

    int descending [] = { 13551, 123, 100, 90, 88, 53, 34, 1, 0, -1, -14 };
    REQUIRE(InAscendingOrder(descending) == false);
    REQUIRE(InNonAscendingOrder(descending));
    REQUIRE(InDescendingOrder(descending));
    REQUIRE(InNonDescendingOrder(descending) == false);

    int none_ascending [] = { 13551, 123, 123, 90, 88, 53, 53, 1, 0, -1, -14 };
    REQUIRE(InAscendingOrder(none_ascending) == false);
    REQUIRE(InNonAscendingOrder(none_ascending));
    REQUIRE(InDescendingOrder(none_ascending) == false);
    REQUIRE(InNonDescendingOrder(none_ascending) == false);

    int singleton [] = { 0 };
    REQUIRE(InAscendingOrder(singleton));
    REQUIRE(InNonAscendingOrder(singleton));
    REQUIRE(InDescendingOrder(singleton));
    REQUIRE(InNonDescendingOrder(singleton));

    int no_order [] = { 1, -1, 0, 314, -4133, 14, 43 };
    REQUIRE(InAscendingOrder(no_order) == false);
    REQUIRE(InNonAscendingOrder(no_order) == false);
    REQUIRE(InDescendingOrder(no_order) == false);
    REQUIRE(InNonDescendingOrder(no_order) == false);
  }
}