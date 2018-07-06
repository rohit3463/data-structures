#include<iostream>
#include<vector>

using namespace std;

struct node{
  int data;
  node *left, *right;
};

struct node* newNode(int data){
  struct node *Node = new node;
  Node->data = data;
  Node->left= nullptr;
  Node->right = nullptr;

  return Node;
}

void make_doubly(vector < node * >& temp,node *& root)
{
	temp[0]->left = nullptr;
	temp[0]->right = temp[1];

	for(int i=1;i<temp.size()-2;i++)
	{
		temp[i]->left = temp[i-1];
		temp[i]->right = temp[i+1];
	}
	temp[temp.size()-1]->left = temp[temp.size()-2];
	temp[temp.size()-1]->right = nullptr;

	root = temp[0];
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

void traverse(node * root)
{
	if(root == nullptr)
	{
		return;
	}
	while(root != nullptr)
	{
		cout<<root->data<<" ";
		root = root->right;
	}
}

int main()
{
	struct node *root  = newNode(10);
    root->left         = newNode(8);
    root->right        = newNode(2);
    root->left->left   = newNode(3);
    root->left->right  = newNode(5);
    root->right->right = newNode(2);

    vector < node * > temp;

    inorder_to_vec(root,temp);

    make_doubly(temp,root);

    traverse(root);

    cout<<endl;

    return 0;

}