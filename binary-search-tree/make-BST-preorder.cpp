#include<iostream>

using namespace std;

struct node
{
	int data;
	node * left = nullptr;
	node * right = nullptr;
};

struct node * newNode(int key)
{
	node * temp = new node;
	temp->data = key;
	temp->left = nullptr;
	temp->right = nullptr;

	return temp;
}

node * insert(node * root,int key)
{
	if(root == nullptr)
	{
		return newNode(key);
	}

	if(key < root->data)
	{
		root->left = insert(root->left,key);
	}
	else if(key > root->data)
	{
		root->right = insert(root->right,key);
	}

	return root;
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

int main()
{
	node * root = nullptr;

	 int pre[] = {10, 5, 1, 7, 40, 50};

	 for(int i=0;i<sizeof(pre)/sizeof(int);i++)
	 {
	 	root = insert(root,pre[i]);
	 }

	 preorder(root);

    cout<<endl;

	return 0;
}