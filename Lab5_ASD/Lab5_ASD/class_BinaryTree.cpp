#include "class_BinaryTree.hpp"

BinaryTree::BinaryTree(){
    root = nullptr;
}

void BinaryTree::Add(char ch) {
    if (root == nullptr) {                 // last node is root
        root = new Node(ch);
        size++;
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
        size++;
        
        if (ch < prev->ch) prev->left = current;
        else prev->right = current;
    }
}



void BinaryTree::Check() {
    queue<char> que;
    if (root == nullptr) {
        cout << "Tree is empty! So it's unable to check letters(" << endl;
    }
    else {
        ReverseReading(root, que);
        int queSize = que.size();
        char array [queSize];
        for (int i = 0; i < queSize; i++) {
            array[i] = que.front();
            que.pop();
        }
        
        //Checking
        vector<char> removingChars;
        
        for (int i = 0; i < queSize - 1; i++) {
            for (int j = 1; j < queSize; j++) {
                if (array[i] == array[j]  &&  !alreadyAdded(array[i], removingChars)  &&  i != j) {
                    removingChars.resize(removingChars.size() + 1);
                    removingChars[removingChars.size() - 1] = array[i];
                }
            }
        }
        
        for (int i = 0; i < removingChars.size(); i++) {
            Delete(removingChars[i], root);
        }
    }
}


bool BinaryTree::alreadyAdded(char ch, vector<char> removingChars) {
    for (int i = 0; i < removingChars.size(); i++) {
        if (ch == removingChars[i]) {
            return true;
        }
    }
    return false;
}

void BinaryTree::Delete(char ch, Node *node){
    if (node->left) Delete(ch, node->left);
    if (node->right) Delete(ch, node->right);
    if (node->ch == ch) {
    
        if (!node->left  &&  !node->right) {                                //leaf removing
            if (node != root) {
                if (node->ch < node->parent->ch) node->parent->left = nullptr;
                else node->parent->right = nullptr;
            }
            else root = nullptr;
        }
        
        else {
            if (node->left  &&  !node->right) {                             //removing node with left
                if (node != root) {
                    if (node->ch < node->parent->ch) {
                        node->parent->left = node->left;
                        node->left->parent = node->parent;
                    }
                    else{
                        node->parent->right = node->left;
                        node->left->parent = node->parent;
                    }
                }
                else{
                    node->left->parent = nullptr;
                    root = node->left;
                }
               
            }
                
            else{
                if (!node->left  &&  node->right) {                          //removing node with right
                    if (node != root) {
                         if (node->ch < node->parent->ch) {
                             node->parent->left = node->right;
                             node->right->parent = node->parent;
                         }
                         else{
                             node->parent->right = node->right;
                             node->right->parent = node->parent;
                         }
                    }
                    else{
                        node->right->parent = nullptr;
                        root = node->right;
                    }
                }
                
                else{
                    Node *newNode = node;                                     //removing node with both
                    newNode = node->left;
                    
                    while (newNode->right) newNode = newNode->right;
                    
                    if (node != root) {
                        if (node->ch < node->parent->ch) node->parent->left = newNode;
                        else node->parent->right = newNode;
        
                        if (newNode->ch < newNode->parent->ch) newNode->parent->left = nullptr;
                        else newNode->parent->right = nullptr ;
                        
                        newNode->parent = node->parent;
                    }
                    else{
                        if (newNode->ch < newNode->parent->ch) newNode->parent->left = nullptr;
                        else newNode->parent->right = nullptr;
                        newNode->parent = nullptr;
                        root = newNode;
                    }
                    
                    if (node->left->parent){
                        node->left->parent = newNode;
                        newNode->left = node->left;
                    }
                    if (node->right->parent){
                        node->right->parent = newNode;
                        newNode->right = node->right;
                    }
                }
            }
        }
        delete node;
    }
}

void BinaryTree::ReverseTreePassingOutput(){
    queue<char> que;
    
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
    }
    else {
        ReverseReading(root, que);
        int queSize = que.size();
        for (int i = 0; i < queSize - 1; i++) {
            cout << que.front() << " -> ";
            que.pop();
        }
        cout << que.front() << endl;
    }
}

void BinaryTree::ReverseReading(Node *node, queue <char> &que){

    if (node->left) ReverseReading(node->left, que);
    if (node->right) ReverseReading(node->right, que);
    que.push(node->ch);
}



/*-----------------------------------------------------------------------------------------------------
-------------------------------------------TREE_OUTPUT-----------------------------------------------*/

void BinaryTree::OutputTree(){
    cout << endl;
    if (root != nullptr) {
        Output(root, 0, "");
    }
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

    if (node->right) Output(node->right, pos+4, str);
    if (node->left){
        if (node->right && node->left) {
            str.erase(str.size() - 4);
            str.append("    ");
        }
        Output(node->left, pos+4, str);
    }
}
