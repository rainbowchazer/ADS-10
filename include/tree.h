// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>
struct Node {
	char c;
	std::vector<Node*> vector;
    explicit Node(char ch) : c(ch) {}
};
class Tree {
private:
    std::vector<std::vector<char>> p;
	Node* root;
    void addNode(Node* root, const std::vector<char>& symbols) {
        for (char ch : symbols) {
            Node* tmp = new Node(ch);
            tmp->c = ch;
            root->vector.push_back(tmp);
            std::vector<char> remainch(symbols);
            remainch.erase(std::find(remainch.begin(), remainch.end(), ch));
            addNode(tmp, remainch);
        }
    }
    void getPermut(Node* root, std::vector<char> symbols) {
        if (root->vector.empty())
            symbols.push_back(root->c);
        if (root->vector.empty()) {
            p.push_back(symbols);
        }
        else {
            for (Node* child : root->vector) {
                getPermut(child, symbols);
            }
        }
    }

public:
    explicit Tree(const std::vector<char>& symb) {
        root = new Node('/0');
        addNode(root, symb);
        std::vector<char> cur;
        getPermut(root, cur);
    }
    std::vector<std::vector<char>> getPermutations() const {
        return p;
    }
};
#endif  // INCLUDE_TREE_H_
