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

void path_vec(node * root,vector < node * >& hello,int data)
{
	static bool flag = false;

	if(root == nullptr)
	{
		return;
	}
	if(root->data == data)
	{
		flag = true;
	}
	if(flag == false)
	{
		path_vec(root->left,hello,data);
	}
	if(flag == false)
	{
		path_vec(root->right,hello,data);
	}

	if(flag == true)
	{
		hello.push_back(root);
		return;
	}

	return;
}
void reverse_vec(vector < node * >& hello)
{
	int temp;
	for(int i = 0;i<hello.size()/2;i++)
	{
		temp = hello[i]->data;
		hello[i]->data = hello[hello.size()-1-i]->data;
		hello[hello.size()-1-i]->data = temp;
	}
}

void reverse_path(node * root,int data)
{
	if(root == nullptr)
	{
		return;
	}

	vector < node * > hello;

	path_vec(root,hello,data);

	reverse_vec(hello);

	return;
}
void inorder(node* root)
{
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
	node* root = newNode(7);
    root->left = newNode(6);
    root->right = newNode(5);
    root->left->left = newNode(10);
    root->left->left->left = newNode(4);
    root->left->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(1);

    int data = 4;

    reverse_path(root,data);

    inorder(root);

    cout<<endl;


 
	return 0;
}