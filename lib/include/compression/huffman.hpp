#pragma once

#include <map>
#include <string>
#include <vector>

namespace oh {
  namespace compression {

struct HuffmanNode {
  HuffmanNode(std::string _str, int _num, HuffmanNode* _left, HuffmanNode* _right)
    : str(_str), num(_num), left(_left), right(_right) {}
  std::string str;
  int num;
  HuffmanNode* left;
  HuffmanNode* right;
};

struct StringOccurrence
{
  StringOccurrence() : str(""), num(0) {}
  StringOccurrence(std::string _str, int _num)
    : str(_str), num(_num) {}
  std::string str;
  int num;

  bool operator==(const StringOccurrence& s) {
    return str==s.str && num==s.num;
  }
};

template <typename T1, typename T2>
struct pair_less_second {
  typedef std::pair<T1, T2> type;
  bool operator ()(type const& a, type const& b) const {
    return a.second < b.second;
  }
};

struct less_huffman_occurrences {
  bool operator()(HuffmanNode* nodeA, HuffmanNode* nodeB) const {
    return nodeA->num < nodeB->num;
  }
};

class StringComparer {
public:
  bool operator()(const std::string s, const std::string w) {
    return s.compare(w) < 0;
  }
};

typedef std::map<std::string, int, StringComparer> StringOccurrences;
typedef std::vector<std::pair<std::string, std::string>> VectorOfStringPair;

void CodeText(std::string file_name, std::string text, int sequence_length = 1);
std::string DecodeText(std::string file_name);

StringOccurrences CountCharsOccurrence(std::string text, int sequence_length = 1);
VectorOfStringPair Huffman(StringOccurrences occurrences);
void PrepareHuffmanCodes(HuffmanNode* node, std::string start_code, VectorOfStringPair& codes);
std::string FindMaximumHuffmanCode(const VectorOfStringPair& codes);
std::string ReplaceCharForHuffmanCode(std::string text, const VectorOfStringPair& codes);
int BinaryStringToULong(std::string text);
std::string ULongToBinaryString(int number);

}}
// ~~ oh::compression
