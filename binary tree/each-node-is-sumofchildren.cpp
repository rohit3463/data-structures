/* 
Source:-https://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/
*/
#include<iostream>

using namespace std;

struct node{
  int data;
  node *left, *right;
};

struct node* newNode(int data){
  struct node *Node = new node;
  Node->data = data;
  Node->left= nullptr;
  Node->right = nullptr;

  return Node;
}

bool sum_property(node *root){

    int new_data;

    if(root == nullptr)
        return true;

    if(root->left != nullptr && root->right == nullptr)
        new_data = root->left->data;

    else if(root->left == nullptr && root->right != nullptr)
        new_data = root->right->data;

    else if(root->left != nullptr && root->right != nullptr)
        new_data = root->left->data + root->right->data;

    else return true;

    if(root->data == new_data){
        return true && sum_property(root->left) && sum_property(root->right);
    }

    else return false;
}

int main(){

    struct node *root  = newNode(10);
      root->left         = newNode(8);
      root->right        = newNode(2);
      root->left->left   = newNode(3);
      root->left->right  = newNode(5);
      root->right->right = newNode(2);
  
      if(sum_property(root))
          cout<<"The given tree satisfies the children sum property"<<endl;

      else cout<<"The given tree doesn't satisfy the children sum property"<<endl;
    return 0;
}