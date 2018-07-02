/*
source - https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
*/
#include<iostream>
#include<vector>

using namespace std;

struct node
{
	int data;
	node * left = nullptr;
	node * right = nullptr;
};
struct node * constr(int key)
{
	node * temp = new node;

	temp->data = key;

	temp->left = nullptr;

	temp->right = nullptr;

	return temp;
}

void morris_inorder(node * root)
{
	if(root == nullptr)
	{
		return;
	}
	node * current = root;
	node * prev = nullptr;

	while(current != nullptr)
	{
		if(current->left == nullptr)
		{
			cout<<current->data<<" ";
			current = current->right;
		}
		else
		{
			prev = current->left;

			while(prev->right != nullptr && prev->right != current)
			{
				prev = prev->right;
			}

			if(prev->right == nullptr)
			{
				prev->right = current;

				current = current->left;
			}
			else
			{
				cout<<current->data<<" ";
				prev->right = nullptr;
				current = current->right;
			}
		}
	}
}

int main()
{

	node * root = constr(1);

	root->left = constr(2);

	root->right = constr(3);

	root->left->left = constr(4);

	root->left->right = constr(5);

	root->right->left = constr(8);

	root->right->right = constr(9);

	root->left->right->left = constr(6);

	root->left->right->right = constr(7);



	morris_inorder(root);

	return 0;

}