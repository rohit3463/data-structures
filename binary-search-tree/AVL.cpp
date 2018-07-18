#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
	int data;
	node * left = nullptr;
	node * right = nullptr;
	int height;
};

struct node * newNode(int key)
{
	node * temp = new node;
	temp->data = key;
	temp->left = nullptr;
	temp->right = nullptr;
	temp->height = 1;

	return temp;
}
int height(node * root)
{
	if(root == nullptr)
	{
		return 0;
	}
	return root->height;
}
node * leftRotate(node * x)
{
	node * y = x->right;
	node * t = y->left;

	y->left = x;
	x->right = t;

	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	return y;
}
node * rightRotate(node * y)
{
	node * x = y->left;
	node * t = x->right;

	x->right = y;
	y->left = t;

	y->height = max(height(x->left),height(x->right)) + 1;
	x->height = max(height(y->left),height(y->right)) + 1;

	return x;

}

int getBalance(node * root)
{
	if(root == nullptr)
	{
		return 0;
	}
	return height(root->left) - height(root->right);
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

	else return root;

	root->height = max(height(root->left),height(root->right)) + 1;

	int balance = getBalance(root);

	if(balance < -1)
	{
		if(key > root->right->data)
		{
			return leftRotate(root);
		}
		if(key < root->right->data)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	if(balance > 1)
	{
		if(key > root->left->data)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if(key < root->left->data)
		{
			return rightRotate(root);
		}
	}

	return root;
}


void inorder(node * root)
{
	if(root == nullptr)
	{
		return;
	}

	inorder(root->left);

	cout<<root->data<<" ";

	inorder(root->right);
}


int main()
{
	node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	inorder(root);

	cout<<endl;
 


    return 0;


}