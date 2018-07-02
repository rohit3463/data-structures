/*
source - https://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes/
*/
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

	node * next = nullptr;
};

struct node * constr(int key)
{
	node * temp = new node;

	temp->data = key;

	temp->left = nullptr;

	temp->right = nullptr;

	temp->next = nullptr;

	return temp;
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
void inorder_next(node * root)
{
	if(root == nullptr)
	{
		return;
	}

	inorder_next(root->left);

	cout<<root->data<<" ";

	if(root->next != nullptr)
	{
		cout<<root->next->data<<endl;
	}
	
	inorder_next(root->right);
}

void inorder_to_vec(node * root,vector < node * >& temp)
{
	if(root == nullptr)
	{
		return;
	}

	inorder_to_vec(root->left,temp);

	temp.push_back(root);

	inorder_to_vec(root->right,temp);
}
vector < node * > populate_vec(vector < node * >& temp)
{
	vector < node * > hello(temp);
	for(int i =0;i<temp.size();i++)
	{
		if(i==temp.size()-1)
		{
			hello[i] = nullptr;
		}
		else
		{
			hello[i] = temp[i+1];
		}
	}

	return hello;
}

void change_tree(node * root,vector < node * >& arr)
{
	static int index = 0;

	if(root == nullptr)
	{
		return;
	}

	change_tree(root->left,arr);

	root->next = arr[index];

	index++;

	change_tree(root->right,arr);
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

	vector < node * > temp;

	inorder_to_vec(root,temp);

	for(auto& y:temp)
	{
		cout<<y->data<<" ";
	}
	cout<<endl;
	cout<<endl;
	temp = populate_vec(temp);

	change_tree(root,temp);

	inorder_next(root);

	cout<<endl;


	return 0;
}