#include <algorithm>
#include <fstream>
#include <iostream>

#include "compression/huffman.hpp"

using namespace std;
using namespace oh::compression;

int main()
{
  int i = 0;
  std::cout << "What to do? (1 write, 2 read): ";
  std::cin >> i;
  ifstream file_in("seneca.txt");

  string str((std::istreambuf_iterator<char>(file_in)),
              std::istreambuf_iterator<char>());

  if (i==1) {
    CodeText("text", str, 1);
  } else {
    string decoded_text = DecodeText("text");

    ofstream file_out("seneca2.txt");
    file_out << decoded_text;
    file_out.close();
  }
}