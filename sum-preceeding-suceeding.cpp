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
void inorder_to_vec(node * root,vector < int >& temp)
{
	if(root == nullptr)
	{
		return;
	}

	inorder_to_vec(root->left,temp);

	temp.push_back(root->data);

	inorder_to_vec(root->right,temp);
}
vector < int > sum_pre_suc(vector < int >& temp)
{
	vector < int > hello(temp);
	for(int i =0;i<temp.size();i++)
	{
		if(i==0)
		{
			hello[i] = temp[i+1];
		}
		else if(i==temp.size()-1)
		{
			hello[i] = temp[i-1];
		}
		else
		{
			hello[i] = temp[i-1] + temp[i+1];
		}
	}

	return hello;
}

void change_tree(node * root,vector < int >& arr)
{
	static int index = 0;

	if(root == nullptr)
	{
		return;
	}

	change_tree(root->left,arr);

	root->data = arr[index];

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

	vector < int > temp;

	inorder_to_vec(root,temp);

	temp = sum_pre_suc(temp);

	change_tree(root,temp);

	inorder(root);



	return 0;
}