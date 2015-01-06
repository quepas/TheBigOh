#include "compression/huffman.hpp"

#include <algorithm>

using std::find;
using std::map;
using std::string;

namespace oh {
  namespace compression {

StringOccurrences CountCharsOccurrence(string text, int chars_group_size /*= 1*/)
{
  StringOccurrences result;
  for (unsigned idx = 0; idx < text.length(); idx += chars_group_size) {
    string sequence = text.substr(idx, chars_group_size);
    if (result.find(sequence) == result.end()) {
      result[sequence] = 1;
    } else {
      ++result[sequence];
    }
  }
  return result;
}

}}
// ~~ oh::compression::
