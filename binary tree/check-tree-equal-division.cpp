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
	temp->right= nullptr;

	return temp;
}

int count(node * root)
{
	if(root == nullptr)
	{
		return 0;
	}

	return count(root->right) + count(root->left) + 1;
}
bool checkRec(node * root,int n)
{
	if(root == nullptr)
	{
		return false;
	}
	if(count(root) == n - count(root))
	{
		return true;
	}

	return checkRec(root->left,n) || checkRec(root->right,n);
}

void check(node * root)
{
	int n = count(root);

	if(checkRec(root,n))
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}

int main()
{
	struct node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->left->left = newNode(3);
    root->right->left = newNode(7);
    root->right->right = newNode(4);
 
 	check(root);

 	return 0;
}