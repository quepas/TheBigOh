#include "compression/huffman.hpp"
#include <catch.hpp>

using oh::compression::CountCharsOccurrence;

TEST_CASE("Counting occurrence of chars in text") {
  SECTION("Standard text with single-char sequences") {
    auto occurrences = CountCharsOccurrence("Standard text", 1);
    REQUIRE(occurrences.size() == 9);
    REQUIRE(occurrences[" "] == 1);
    REQUIRE(occurrences["S"] == 1);
    REQUIRE(occurrences["t"] == 3);
    REQUIRE(occurrences["a"] == 2);
    REQUIRE(occurrences["n"] == 1);
    REQUIRE(occurrences["d"] == 2);
    REQUIRE(occurrences["r"] == 1);
    REQUIRE(occurrences["e"] == 1);
    REQUIRE(occurrences["x"] == 1);
    auto occurrences_2 = CountCharsOccurrence("Ala lala laall");
    REQUIRE(occurrences_2.size() == 4);
    REQUIRE(occurrences_2["A"] == 1);
    REQUIRE(occurrences_2["a"] == 5);
    REQUIRE(occurrences_2["l"] == 6);
    REQUIRE(occurrences_2[" "] == 2);
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
    auto occurrences = CountCharsOccurrence("Standard text", 2);
    REQUIRE(occurrences.size() == 7);
    REQUIRE(occurrences["St"] == 1);
    REQUIRE(occurrences["an"] == 1);
    REQUIRE(occurrences["da"] == 1);
    REQUIRE(occurrences["rd"] == 1);
    REQUIRE(occurrences[" t"] == 1);
    REQUIRE(occurrences["ex"] == 1);
    REQUIRE(occurrences["t"] == 1);
    auto occurrences_2 = CountCharsOccurrence("Ala lala laall", 4);
    REQUIRE(occurrences_2.size() == 4);
    REQUIRE(occurrences_2["Ala "] == 1);
    REQUIRE(occurrences_2["lala"] == 1);
    REQUIRE(occurrences_2[" laa"] == 1);
    REQUIRE(occurrences_2["ll"] == 1);
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
    auto occurrences_4 = CountCharsOccurrence(" $%&\t&$\n\t", 3);
    REQUIRE(occurrences_4.size() == 3);
    REQUIRE(occurrences_4[" $%"] == 1);
    REQUIRE(occurrences_4["&\t&"] == 1);
    REQUIRE(occurrences_4["$\n\t"] == 1);
    auto occurrences_5 = CountCharsOccurrence("ABCDA", 3);
    REQUIRE(occurrences_5.size() == 2);
    REQUIRE(occurrences_5["ABC"] == 1);
    REQUIRE(occurrences_5["DA"] == 1);
  }
}