#include "Libs.hpp"
#include "class_BinaryTree.hpp"
#include "mainFunctions.hpp"

int main() {
    string str;
    cout << "Write letters: "; cin >> str;
    
    BinaryTree tree;
    CharsToTree(str);
    
    tree.Check();
    
    tree.ReverseOutput();
    
    return 0;
}
