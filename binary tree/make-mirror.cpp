/*
Source :-https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
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

void make_mirror(node * root)
{
	if(root == nullptr)
	{
		return;
	}
	node * temp = root->left;
	root->left = root->right;
	root->right = temp;

	make_mirror(root->left);

	make_mirror(root->right);
}

void inorder_traverse(node * root)
{
	if(root == nullptr)
	{
		return;
	}

	inorder_traverse(root->left);

	cout<<root->data<<" ";

	inorder_traverse(root->right);
}


int main()
{
	struct node *root  = newNode(10);
    root->left         = newNode(8);
    root->right        = newNode(2);
    root->left->left   = newNode(3);
    root->left->right  = newNode(5);
    root->right->right = newNode(2);

    inorder_traverse(root);

    cout<<endl;

    make_mirror(root);

    inorder_traverse(root);

    cout<<endl;
}