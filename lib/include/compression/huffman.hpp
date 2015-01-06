#pragma once

#include "data/binary_tree.hpp"

#include <map>
#include <string>

namespace oh {
  namespace compression {

struct StringOccurrence
{
  StringOccurrence(std::string _str, int _occurrence)
    : str(_str), occurrence(_occurrence) {}
  std::string str;
  int occurrence;
};

class StringComparer {
public:
  bool operator()(const std::string s, const std::string w) {
    return s.compare(w) < 0;
  }
};

typedef std::map<std::string, int, StringComparer> StringOccurrences;

StringOccurrences CountCharsOccurrence(std::string text, int sequence_length = 1);
std::string FindMinOccurrence(StringOccurrences occurrences);
std::pair<std::string, std::string> FindTwoMinOccurrence(StringOccurrences occurrences);

data::BinaryTree<StringOccurrence> Huffman(StringOccurrences occurrences);

}}
// ~~ oh::compression
