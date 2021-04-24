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
    
public:
    BinaryTree();
    void Add(char);
    void Check();
    void Delete(Node*);
    void ReverseOutput();
};
