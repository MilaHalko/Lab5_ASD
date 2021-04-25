#include "mainFunctions.hpp"

string StringInput(){
    string str;
    cout << "Write letters: "; cin >> str;
    cout << endl;
    return str;
}

void CharsToTree(string str, BinaryTree &tree) {
    for (int i = 0; i < str.size(); i++) {
        tree.Add(str[i]);
    }
}
