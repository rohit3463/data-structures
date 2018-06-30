#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

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

void preorder(node * root)
{
	if(root == nullptr)
	{
		return;
	}
	cout<<root->data<<" ";

	preorder(root->left);

	preorder(root->right);
}

void mirror_inorder(node * root)
{
	if(root == nullptr)
	{
		return;
	}
	mirror_inorder(root->right);

	cout<<root->data<<" ";

	mirror_inorder(root->left);
}
int main()
{

	node * root = constr(1);

	root->left = constr(2);

	root->right = constr(3);

	root->left->left = constr(4);

	root->left->right = constr(5);

	root->right->left = constr(6);

	root->right->right = constr(7);

	mirror_inorder(root);


	return 0;
}