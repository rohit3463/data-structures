#include <iostream>
#include<vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* newNode(int item) {
    node* temp =  new node;
    temp->data = item;
    temp->left = temp->right = nullptr;

    return temp;
}
node * getNode(node * root,int key)
{
	if(root == nullptr)
	{
		return newNode(key);
	}

	if(key < root->data)
	{
		root->left = getNode(root->left,key);
	}
	else if(key > root->data)
	{
		root->right = getNode(root->right,key);
	}

	return root;
}

void inorder_to_vec(node * root,vector< int >& temp)
{
	if(root == nullptr)
	{
		return;
	}
	inorder_to_vec(root->left,temp);

	temp.push_back(root->data);

	inorder_to_vec(root->right,temp);
}

void preorder(node *& root,vector < int > temp)
{
	static int index = 0;
	if(root == nullptr)
	{
		return;
	}

	root->data = temp[index];
	cout<<root->data<<" ";
	index++;

	preorder(root->left,temp);

	preorder(root->right,temp);

}

void convert_to_min_heap(node *& root)
{
	vector < int > temp;

	inorder_to_vec(root,temp);

	preorder(root,temp);
}
int main()
{
	node * root = nullptr;
    root = getNode(root,4);
    root = getNode(root,2);
    root = getNode(root,6);
    root = getNode(root,1);
    root = getNode(root,3);
    root = getNode(root,5);
    root = getNode(root,7);

    convert_to_min_heap(root);

    cout<<endl;
 
    return 0;
}