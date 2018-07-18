#include<iostream>
#include<vector>
#include<algorithm>

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

void vec_to_BST(node * root,vector< int >& temp,int& index)
{
	if(root == nullptr)
	{
		return;
	}
	vec_to_BST(root->left,temp,index);

	root->data = temp.at(index);

	index++;

	vec_to_BST(root->right,temp,index);
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
	node * root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    vector< int > temp;

    inorder_to_vec(root,temp);

    sort(temp.begin(), temp.end());

    int index = 0;

    vec_to_BST(root,temp,index);

    inorder(root);



    cout<<endl;

	return 0;
}