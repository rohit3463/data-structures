#include<iostream>

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

int sum = 0;

void inorder(node * root,int flag)
{
	if(root == nullptr)
	{
		return;
	}

	inorder(root->left,1);

	if(root->left == nullptr && root->right == nullptr && flag == 1)
	{
		sum += root->data;
	}

	inorder(root->right,2);
}

int main()
{
	struct node *root         = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(52);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(12);

    inorder(root,0);

    cout<<sum<<endl;
}