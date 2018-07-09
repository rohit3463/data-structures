#include<iostream>
#include<vector>

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

void printvec(vector < int > temp)
{
	for(auto& y:temp)
	{
		cout<<y<<" ";
	}
	cout<<endl;
}

void print_all_leaf_path(node * root,vector < int > temp)
{
	if(root == nullptr)
	{
		return;
	}

	temp.push_back(root->data);

	if(root->left == nullptr && root->right == nullptr)
	{
		printvec(temp);
		return;
	}

	if(root->left != nullptr)
	{
		print_all_leaf_path(root->left,temp);
	}
	if(root->right != nullptr)
	{
		print_all_leaf_path(root->right,temp);
	}

	return;

}

int main()
{
	vector < int > temp;
	struct node *root = newNode(1);
 	root->left        = newNode(2);
 	root->right       = newNode(3);
 	root->left->left  = newNode(4);
  	root->left->right = newNode(5); 

  	print_all_leaf_path(root,temp);
	return 0;
}