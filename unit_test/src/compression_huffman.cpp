#include "compression/huffman.hpp"
#include <catch.hpp>

using oh::compression::CountCharsOccurrence;

TEST_CASE("Counting occurrence of chars in text") {
  SECTION("Standard text with single-char sequences") {
    auto occurrences = CountCharsOccurrence("Standard text", 1);
    REQUIRE(occurrences.size() == 9);
  }

  SECTION("Non-standard crazy text with single char sequences") {
    auto occurrences_1 = CountCharsOccurrence("");
    REQUIRE(occurrences_1.empty());
    auto occurrences_2 = CountCharsOccurrence(" ");
    REQUIRE(occurrences_2.size() == 1);
    REQUIRE_NOTHROW(occurrences_2[" "]);
    REQUIRE(occurrences_2[" "] == 1);
    auto occurrences_3 = CountCharsOccurrence(" $%&\t&$\n\t");
    REQUIRE(occurrences_3.size() == 6);
    REQUIRE(occurrences_3[" "] == 1);
    REQUIRE(occurrences_3["$"] == 2);
    REQUIRE(occurrences_3["&"] == 2);
    REQUIRE(occurrences_3["\t"] == 2);
    REQUIRE(occurrences_3["%"] == 1);
    REQUIRE(occurrences_3["\n"] == 1);
  }

  SECTION("Standard text with multiple char sequences") {

  }

  SECTION("Non-standard crazy text with multiple char sequences") {
    auto occurrences_1 = CountCharsOccurrence("", 2);
    REQUIRE(occurrences_1.empty());
    auto occurrences_2 = CountCharsOccurrence(" ", 2);
    REQUIRE(occurrences_2.size() == 1);
    REQUIRE_NOTHROW(occurrences_2[" "]);
    REQUIRE(occurrences_2[" "] == 1);
    auto occurrences_3 = CountCharsOccurrence(" $%&\t&$\n\t", 2);
    REQUIRE(occurrences_3.size() == 5);
    REQUIRE(occurrences_3[" $"] == 1);
    REQUIRE(occurrences_3["%&"] == 1);
    REQUIRE(occurrences_3["\t&"] == 1);
    REQUIRE(occurrences_3["$\n"] == 1);
    REQUIRE(occurrences_3["\t"] == 1);
  }
}