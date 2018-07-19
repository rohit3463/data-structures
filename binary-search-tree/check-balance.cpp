#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct node {
    int key;
    node* left;
    node* right;
};

node* newNode(int item) {
    node* temp =  new node;
    temp->key = item;
    temp->left = temp->right = nullptr;

    return temp;
}

int isBalanced(node* root, bool& flag) {
    if(root == nullptr)
        return 0;
    
    int l = isBalanced(root->left, flag);
    int r = isBalanced(root->right, flag);

    if(abs(l-r) > 1) {
        flag = false;
    }

    return 1 + max(l, r);
}

int main() {
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    bool flag = true;
    isBalanced(root, flag);

    if(flag)
        cout<<"Balanced\n";
    else    
        cout<<"Unbalanced\n";

    return 0;
}