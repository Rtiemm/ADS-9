#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <fstream>
#include <iostream>
#include <string>

template <typename T>
struct Node {
  Node<T>* left = nullptr;
  Node<T>* right = nullptr;
  int count = 0;
  T value = "";
};
template <typename T>
class BST {
 private:
  Node<T>* root = nullptr;
  int depthV = 0;

 public:
  BST() {
    root = nullptr;
    depthV = 0;
  }
  void PrintT(Node<T>* tree, int i) {
    std::cout << i << "-----" << tree->value << "\n";
    ++i;
    if (tree->left != nullptr) {
      PrintTree(tree->left, i);
    }
    if (tree->right != nullptr) {
      PrintTree(tree->right, i);
    }
    return;
  }
  void Get_Depth(Node<T>* tree, int i) {
    ++i;
    if (tree->left != nullptr) {
      Get_Depth(tree->left, i);
    }
    if (tree->right != nullptr) {
      Get_Depth(tree->right, i);
    }
    if (i > depthV) depthV = i;
  }
  void Add(T val) {
    Node<T>* current = root;
    if (current == nullptr) {
      current = new Node<T>;
      current->left = nullptr;
      current->right = nullptr;
      current->value = val;
      current->count += 1;
      root = current;
      return;
    } else {
      Node<T>* past = nullptr;
      bool isleft = false;
      while (true) {
        if (current == nullptr) {
          current = new Node<T>;
          current->left = nullptr;
          current->right = nullptr;
          current->value = val;
          current->count += 1;
          if (past != nullptr) {
            if (isleft == true) {
              past->left = current;
            } else {
              past->right = current;
            }
            past = nullptr;
          }
          break;
        } else if (val == current->value) {
          current->count += 1;
          break;
        } else if (val > current->value) {
          isleft = false;
          past = current;
          current = current->right;
        } else if (val < current->value) {
          isleft = true;
          past = current;
          current = current->left;
        }
      }
    }
  }
  int Search(T val) {
    Node<T>* current = root;
    while (true) {
      if (current->value == val) {
        return current->count;
      } else if (val > current->value) {
        current = current->right;
      } else if (val < current->value) {
        current = current->left;
      }
    }
  }
  int Depth() {
    Node<T>* current = root;
    Get_Depth(current, 0);
    return depthV - 1;
  }

  void PrintTree() {
    Node<T>* current = root;
    PrintT(current, 0);
  }
};
#endif  // INCLUDE_BST_H_
