/*
source - https://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation/
*/
#include<iostream>

using namespace std;

struct mytree
{
	int data;
	mytree * left = nullptr;
	mytree * right = nullptr;
};
void tree_from_array(int arr[],int index,mytree *& node,int size)
{
	if(index < size)
	{
		node = new mytree;

		node->data = arr[index];

		tree_from_array(arr,2*index + 1,node->left,size);

		tree_from_array(arr,2*index + 2,node->right,size);

	}
	return;
}
void inorder_traverse(mytree * root)
	{
		if(root == nullptr)
			return;

		inorder_traverse(root->left);

		cout<<root->data<<" ";

		inorder_traverse(root->right);

		return;
	}

int main()
{
	mytree * root = nullptr;
	int size;

	int arr[6] = {10,12,15,25,30,36};

	size = sizeof(arr)/sizeof(int);

	tree_from_array(arr,0,root,size);

	inorder_traverse(root);

	return 0;
}