// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>
struct Node {
	bool exam = false;
	char c;
	std::vector<Node*> vector;
    explicit Node(char ch) : c(ch) {}
};
class Tree {
private:
  std::vector<std::vector<char>> p;
Node* root;
  void addNode(Node * root, const std::vector<char>&symbols) {
    for (char ch : symbols) {
      Node* tmp = new Node;
      tmp->c = ch;
      root->nodes.push_back(tmp);
      std::vector<char> remainch(symbols);
      remainch.erase(std::find(remainch.begin(), remainch.end(), ch));
      addNode(tmp, remainch);
    }
  }
    void getPermut(Node * root, std::vector<char> symbols) {
    if (!root->exam)
      symbols.push_back(root->c);
    if (root->vector.empty()) {
      p.push_back(symbols);
    } else {
      for (Node* son : root->vector) {
        getPermut(son, symbols);
      }
    }
  }

public:
    explicit Tree(const std::vector<char>& symb) {
        root = new Node;
    root->exam = true;
    addNode(root, symb);
    std::vector<char> current;
   getPermut(root, current);
  }
  std::vector<std::vector<char>> getPermutations() const {
    return p;
  }
};
#endif  // INCLUDE_TREE_H_
