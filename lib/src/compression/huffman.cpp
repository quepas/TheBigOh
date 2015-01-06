#include "compression/huffman.hpp"

#include <algorithm>

using oh::data::BinaryTree;
using std::find;
using std::pair;
using std::map;
using std::make_pair;
using std::string;

namespace oh {
  namespace compression {

StringOccurrences CountCharsOccurrence(string text, int sequence_length /*= 1*/)
{
  StringOccurrences result;
  for (unsigned idx = 0; idx < text.length(); idx += sequence_length) {
    string sequence = text.substr(idx, sequence_length);
    if (result.find(sequence) == result.end()) {
      result[sequence] = 1;
    } else {
      ++result[sequence];
    }
  }
  return result;
}

pair<string, string> FindTwoMinOccurrence(StringOccurrences occurrences)
{
  string first_occurrence = FindMinOccurrence(occurrences);
  occurrences.erase(first_occurrence);
  return make_pair(first_occurrence, FindMinOccurrence(occurrences));
}

string FindMinOccurrence(StringOccurrences occurrences)
{
  int min_occurrence = INT_MAX;
  string min_str = "";
  for (auto it = occurrences.begin(); it != occurrences.end(); ++it) {
    if (it->second < min_occurrence) {
      min_str = it->first;
      min_occurrence = it->second;
    }
  }
  return min_str;
}

data::BinaryTree<StringOccurrence> Huffman(StringOccurrences occurrences)
{
  if (occurrences.size() == 2) {
    auto it = occurrences.begin();
    auto first = StringOccurrence(it->first, it->second);
    ++it;
    auto second = StringOccurrence(it->first, it->second);
    BinaryTree<StringOccurrence> tree(StringOccurrence("", first.occurrence + second.occurrence));
    tree.AddLeftChild(first);
    tree.AddRightChild(second);
    return tree;
  }

  auto min_occurrences = FindTwoMinOccurrence(occurrences);
  auto left = occurrences.find(min_occurrences.first);
  auto right = occurrences.find(min_occurrences.second);

  occurrences.erase(left->first);
  occurrences.erase(right->first);
  occurrences[left->first+right->first] = left->second + right->second;
  auto tree = Huffman(occurrences);
}

}}
// ~~ oh::compression::
