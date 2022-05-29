#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

#include "bst.h"

BST<std::string> makeTree(const char* name) {
  BST<std::string> tree;
  std::ifstream file(name);
  if (!file) {
    std::cout << "Something wrong"
              << "\n";
    throw std::string("Can not open file!");
  }
  std::string word = "";
  while (!file.eof()) {
    char IdontWantToDoIt = file.get();
    int ch = IdontWantToDoIt;
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
      word += tolower(ch);
    } else {
      if (word != "") {
        tree.Add(word);
        word = "";
      }
    }
  }
  file.close();
  return tree;
}
