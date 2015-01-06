#pragma once

#include <map>
#include <string>

namespace oh {
  namespace compression {

class StringComparer {
public:
  bool operator()(const std::string s, const std::string w) {
    return s.compare(w) < 0;
  }
};

typedef std::map<std::string, int, StringComparer> StringOccurrences;

StringOccurrences CountCharsOccurrence(std::string text, int sequence_length = 1);

}}
// ~~ oh::compression
