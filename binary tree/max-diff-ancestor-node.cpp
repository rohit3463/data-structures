#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

struct node 
{
	int data;
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

int send_min(node * root)
{
	if(root == nullptr)
	{
		return INT_MAX;
	}

	int left_min = send_min(root->left);
	int right_min = send_min(root->right);

	if((root->data - left_min)>global_max)
	{
		global_max = root->data - left_min;
	}
	if((root->data - right_min) > global_max)
	{
		global_max = root->data - right_min;
	}

	return min(root->data,min(left_min,right_min));
}

int main()
{
	node* root;
    root = newNode(8);
    root->left = newNode(3);
 
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    send_min(root);

    cout<<global_max<<endl;
 
	return 0;
}