#pragma once
#include "Libs.hpp"

struct Node {
    char ch;
    Node *parent;
    Node *left;
    Node *right;
    
    Node(char ch = '\0', Node *parent = nullptr, Node *left = nullptr, Node *right = nullptr){
        this->ch = ch;
        this->parent = parent;
        this->left = left;
        this->right = right;
    }
};

class BinaryTree {
    Node *root;
    int size;
    void Output(Node*, int, string);
    void ReverseReading(Node*, queue <char> &);
    bool alreadyAdded(char, vector<char>);
    
public:
    BinaryTree();
    void Add(char);
    void Check();
    void Delete(char, Node*);
    void OutputTree();
    void ReverseTreePassingOutput();
};
