/*
source:-https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
*/

#include <iostream>

using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

node* newNode(int data) {
  struct node *temp = new node;
  temp->data = data;
  temp->left = nullptr;
  temp->right = nullptr;
 
  return temp;
}

int sumtree(node* root) {
    if(root == nullptr)
    {
        return 0;
    }
    int old_value = root->data;

    root->data = sumtree(root->left) + sumtree(root->right);

    return old_value+root->data;
}

void inoder(node* root) {
    if(root) {
        inoder(root->left);
        cout<<root->data<<" ";
        inoder(root->right);
    }
}

int main() {
    node*  root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    sumtree(root);
    inoder(root);

    cout<<endl;

    return 0;
}