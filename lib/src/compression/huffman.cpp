#include "compression/huffman.hpp"

#include <algorithm>
#include <cassert>
#include <deque>

using std::deque;
using std::find;
using std::pair;
using std::map;
using std::make_pair;
using std::string;
using std::vector;

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

VectorOfStringPair Huffman(StringOccurrences occurrences)
{
  assert(occurrences.size() > 1);

  vector<pair<string, int>> sorted_occurr(occurrences.begin(), occurrences.end());
  sort(sorted_occurr.begin(), sorted_occurr.end(), pair_less_second<string, int>());
  deque<HuffmanNode*> queue;

  for (auto it = sorted_occurr.begin(); it != sorted_occurr.end(); ++it) {
    queue.push_back(new HuffmanNode(it->first, it->second, nullptr, nullptr));
  }
  while(queue.size() > 1) {
    auto p = queue.front(); queue.pop_front();
    auto q = queue.front(); queue.pop_front();
    HuffmanNode* node = new HuffmanNode("", p->num + q->num, p, q);

    queue.push_front(node);
    sort(queue.begin(), queue.end(), less_huffman_occurrences());
  }
  HuffmanNode* root = queue.front();
  VectorOfStringPair codes;
  PrepareHuffmanCodes(root, "", codes);
  return codes;
}

void PrepareHuffmanCodes(HuffmanNode* node, string start_code, VectorOfStringPair& codes) {
  if (!node->left && !node->right) {
    codes.push_back(make_pair(node->str, start_code));
    return;
  }
  if (node->left)
    PrepareHuffmanCodes(node->left, start_code+"0", codes);
  if (node->right)
    PrepareHuffmanCodes(node->right, start_code+"1", codes);
}

}}
// ~~ oh::compression::
