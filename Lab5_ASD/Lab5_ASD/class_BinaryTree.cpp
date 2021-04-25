#include "class_BinaryTree.hpp"

BinaryTree::BinaryTree(){
    root = nullptr;
}

void BinaryTree::Add(char ch) {
    if (root == nullptr) {                 // last node is root
        root = new Node(ch);
    }
    else {
        Node *current = root;
        Node *prev = nullptr;
        while (current != nullptr) {        // last node searching
            if (ch < current->ch) {
                prev = current;
                current = current->left;
            }
            else{
                prev = current;
                current = current->right;
            }
        }
        
        current = new Node(ch, prev);       // new node
        
        if (ch < prev->ch) {
            prev->left = current;
        }
        else {
            prev->right = current;
        }
    }
}



void BinaryTree::Check() {
    
}

void BinaryTree::Delete(Node* parent){
    
}

void BinaryTree::ReverseReading(){
    
}



/*-----------------------------------------------------------------------------------------------------
-------------------------------------------TREE_OUTPUT-----------------------------------------------*/

void BinaryTree::OutputTree(){
    Output(root, 0, "");
}

void BinaryTree::Output(Node *node, int pos, string str) {
    
    string subStr = "";
    
    //~~~NEXT_NODE_OUTPUT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    if (node) {
        if (node->left  &&  node->right) str += "|   ";
        else str += "    ";
        
        for (int i = 0; i < pos-4; i++) {
            cout << str[i];
        }
        
        if (node == root) cout << node->ch << endl;
        else cout  << "|___" << node->ch << endl;
    }
    
    //~~~SUBLINE_FOR_EASIER_READING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    if ((!node->left  &&  node->right)  ||  (node->left  &&  !node->right)) {   // left or right exists
        cout << str.substr(0, str.size() - 4) << "|" << endl;
    }
    else
        if (node->left  && node->right){                                        // both exists
            cout << str << endl;
    }
        else cout << str.substr(0, str.size() - 4) << endl;                     // a leaf
    
    //~~~NEXT_NODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    if (node->right){
        Output(node->right, pos+4, str);
    }
    if (node->left){
        if (node->right && node->left) {
            str.erase(str.size() - 4);
            str.append("    ");
        }
        Output(node->left, pos+4, str);
    }
}
