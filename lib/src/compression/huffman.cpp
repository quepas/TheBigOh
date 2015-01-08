#include "compression/huffman.hpp"

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <fstream>

#include <iostream>

using std::bitset;
using std::ceil;
using std::cout;
using std::deque;
using std::endl;
using std::find;
using std::ifstream;
using std::pair;
using std::map;
using std::make_pair;
using std::ofstream;
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

void CodeText(string file_name, string text, int sequence_length /*= 1*/)
{
  auto occurrences = CountCharsOccurrence(text, sequence_length);
  auto huffman_codes = Huffman(occurrences);

  // write huffman codes
  ofstream file_out(file_name, std::ios::binary);
  if (!file_out.is_open()) return;

  // write sequence length
  file_out.write((char*)&sequence_length, sizeof(int));
  // write max_code length
  int max_code_length = FindMaximumHuffmanCode(huffman_codes).size();
  file_out.write((char*)&max_code_length, sizeof(int));
  // write codes num
  int num_codes = huffman_codes.size();
  file_out.write((char*)&num_codes, sizeof(int));
  // write codes one by one
  for (unsigned i = 0; i < num_codes; ++i) {
    string str = huffman_codes[i].first;
    string code = huffman_codes[i].second;
    file_out.write(str.c_str(), sizeof(char)*(sequence_length+1));
    file_out.write(code.c_str(), sizeof(char)*(max_code_length+1));
  }
  // code text
  string text_coded = ReplaceCharForHuffmanCode(text, huffman_codes);
  // number bytes to write
  int num_data_bytes = ceil(text_coded.size()/8.0);
  file_out.write((char*)&num_data_bytes, sizeof(int));
  // write coded text byte by byte
  for (unsigned i = 0; i < text_coded.size(); i+=8) {
    string byte_slice = text_coded.substr(i, 8);
    if (byte_slice.size() < 8) {
      byte_slice.append(8 - byte_slice.size(), '0');
    }
    char byte = BinaryStringToULong(byte_slice);
    file_out.write((char*)&byte, sizeof(char));
  }
  cout << "================ " << file_name << " ================";
  cout << "\nCoded file size=" << file_out.tellp();
  cout << "\n\tNum of codes=" << num_codes;
  cout << "\n\tMax. code length=" << max_code_length;
  cout << "\n\tCharacter sequence length=" << sequence_length << endl;
  file_out.close();
}

std::string DecodeText(std::string file_name)
{
  ifstream file_in(file_name, std::ios::binary);
  if (!file_in.is_open()) return "NA";
  map<string, string, StringComparer> codes_map;
  // read sequence length
  int sequence_length;
  file_in.read(reinterpret_cast<char*>(&sequence_length), sizeof(int));
  // read max_code_length
  int max_code_length;
  file_in.read(reinterpret_cast<char*>(&max_code_length), sizeof(int));
  // read codes num
  int num_codes;
  file_in.read((char*)&num_codes, sizeof(int));
  // read codes one by one
  char* str = new char[sequence_length+1];
  char* code = new char[max_code_length+1];
  for (int i = 0; i < num_codes; ++i) {
    file_in.read(str, sizeof(char)*(sequence_length+1));
    file_in.read(code, sizeof(char)*(max_code_length+1));
    codes_map[string(code)] = string(str);
  }
  delete [] str;
  delete [] code;

  // read num bytes to read
  int num_data_bytes;
  file_in.read((char*)&num_data_bytes, sizeof(int));
  // read data
  string* data = new string();
  for (int i = 0; i < num_data_bytes; ++i) {
    char byte;
    file_in.read((char*)&byte, sizeof(char));
    (*data) += ULongToBinaryString(byte);
  }

  // retrive decoded text
  string decoded_text = "";
  int offset = 0;
  bool no_more = false;
  while (offset < data->size() && !no_more) {
    for (int i = 1; i <= max_code_length; ++i) {
      string probable_code = data->substr(offset, i);
      if (codes_map.find(probable_code) != codes_map.end()) {
        string s = codes_map[probable_code];
        decoded_text += s;
        offset += i;
        break;
      }
      if (i == max_code_length) no_more = true;
    }
  }
  cout << "================ " << file_name << " ================";
  cout << "\nCoded file size=" << file_in.tellg();
  cout << "\n\tNum of codes=" << num_codes;
  cout << "\n\tMax. code length=" << max_code_length;
  cout << "\n\tCharacter sequence length=" << sequence_length << endl;

  file_in.close();
  return decoded_text;
}

string FindMaximumHuffmanCode(const VectorOfStringPair& codes)
{
  string max_code = "";
  for (unsigned i = 0; i< codes.size(); ++i) {
    if (codes[i].second.size() > max_code.size()) {
      max_code = codes[i].second;
    }
  }
  return max_code;
}

string ReplaceCharForHuffmanCode(string text, const VectorOfStringPair& codes)
{
  string result = "";
  map<string, string, StringComparer> codes_map;
  // copy codes from vector to map
  for (unsigned i = 0; i < codes.size(); ++i) {
    codes_map[codes[i].first] = codes[i].second;
  }
  for (unsigned i = 0; i < text.length(); ++i) {
    result += codes_map[string(1, text[i])];
  }
  return result;
}

int BinaryStringToULong(string text)
{
  bitset<8> bs(text);
  return bs.to_ulong();
}

string ULongToBinaryString(int number)
{
  bitset<8> bs(number);
  return bs.to_string();
}

}}
// ~~ oh::compression::
