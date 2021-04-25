#include "Libs.hpp"
#include "class_BinaryTree.hpp"
#include "mainFunctions.hpp"

int main() {
    string str = "adbcedafhg";
    //string str = StringInput();
    
    BinaryTree tree;
    
    CharsToTree(str, tree);
    tree.OutputTree();
    
    tree.Check();
    tree.OutputTree();
    
    tree.ReverseReading();
    
    return 0;
}
