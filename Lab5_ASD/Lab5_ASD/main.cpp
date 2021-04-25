#include "Libs.hpp"
#include "class_BinaryTree.hpp"
#include "mainFunctions.hpp"

int main() {

    string str = StringInput();
    
    BinaryTree tree;
    
    CharsToTree(str, tree);
    tree.OutputTree();
    tree.ReverseTreePassingOutput();
    
    tree.Check();
    tree.OutputTree();
    tree.ReverseTreePassingOutput();
    
    return 0;
}
