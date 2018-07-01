#include<iostream>
#include<vector>

using namespace std;

struct node
{
	int data;
	node * left = nullptr;
	node * right = nullptr;
	bool threaded;
};

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
struct node * constr(int key)
{
	node * temp = new node;

	temp->data = key;

	temp->left = nullptr;

	temp->right = nullptr;

	temp->threaded = false;

	return temp;
}

void put_threads(vector < node * >& temp)
{
	for(int i=0;i<(temp.size()-1);i++)
	{
		if(temp[i]->right == nullptr)
		{
			temp[i]->right = temp[i+1];
			temp[i]->threaded = true;
		}
	}
	temp[temp.size()-1]->right = nullptr;
	
}

struct node * leftmost(node * temp)
{
	if(temp == nullptr)
	{
		return nullptr;
	}

	while(temp->left != nullptr)
	{
		temp = temp->left;
	}

	return temp;
}

void inorder_traversal_with_threads(node * root)
{
	node * temp = leftmost(root);

	while(temp != nullptr)
	{
		cout<<temp->data<<" ";

		if(temp->threaded == true)
		{
			temp = temp->right;
		}
		else
		{
			temp = leftmost(temp->right);
		}
	}


}
int main()
{
	vector < node * > temp;

	node * root = constr(1);

	root->left = constr(2);

	root->right = constr(3);

	root->left->left = constr(4);

	root->left->right = constr(5);

	root->right->left = constr(6);

	root->right->right = constr(7);

	inorder_to_vec(root,temp);

	put_threads(temp);

	inorder_traversal_with_threads(root);

	cout<<endl;


}