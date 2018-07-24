#include <iostream>
#include <utility>
#include <climits>

using namespace std;

struct node {
    int data;
    int size = 1;
    node* left = nullptr;
    node* right = nullptr;
};

typedef pair<int, int> Pair; 
int max_size = 1;

node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    return temp;
}

Pair subtreeBST(node* root) {
    if(root == nullptr)
        return make_pair(INT_MIN, INT_MAX);
    
    Pair l = subtreeBST(root->left);
    Pair r = subtreeBST(root->right);

    if(root->left && root->data > l.first)
        root->size += root->left->size;

    if(root->right && root->data < r.second)
        root->size += root->right->size;

    max_size = (root->size > max_size ? root->size : max_size);

    return make_pair(
        max(root->data, max(l.first, r.first)), 
        min(root->data, min(r.second, l.second))
    );
}

int main(){
    node *root                = newNode(50);
    root->left                = newNode(10);
    root->right               = newNode(60);
    root->left->left          = newNode(5);
    root->left->right         = newNode(20);
    root->right->left         = newNode(55);
    root->right->left->left   = newNode(45);
    root->right->right        = newNode(70);
    root->right->right->left  = newNode(65);
    root->right->right->right = newNode(80);

    subtreeBST(root);

    cout<<max_size<<endl;

    return 0;
}