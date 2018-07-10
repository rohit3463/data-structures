#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

struct node 
{
	char data;
	node * left = nullptr;
	node * right = nullptr;
};

struct node * newNode(char key)
{
	node * temp = new node;

	temp->data = key;
	temp->left = nullptr;
	temp->right= nullptr;

	return temp;
}

int global_max = INT_MIN;

int maximum_leaf_to_leaf(node * root)
{
	if(root==nullptr)
	{
		return 0;
	}
	int left = maximum_leaf_to_leaf(root->left);
	int right = maximum_leaf_to_leaf(root->right);

	if(global_max < (root->data + left +right))
	{
		global_max = root->data + left +right;
	}

	return max(root->data+left,root->data+right);
}

int main()
{
	struct node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
	
    maximum_leaf_to_leaf(root);

    cout<<global_max<<endl;

	return 0;
}