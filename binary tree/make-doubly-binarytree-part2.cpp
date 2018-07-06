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

void inorder_make_doubly(node * root,node *& head)
{
	if(root == nullptr)
	{
		return;
	}
	static node * prev = nullptr;

	inorder_make_doubly(root->left,head);

	if(prev == nullptr)
	{
		head = root;
	}
	else
	{
		root->left = prev;
		prev->right = root; 
	}

	prev = root;

	inorder_make_doubly(root->right,head);
}

void traverse_doubly(node * head)
{
	if(head==nullptr)
	{
		return;
	}
	while(head != nullptr)
	{
		cout<<head->data<<" ";
		head = head->right;
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

    node * head = nullptr;

    inorder_make_doubly(root,head);

    traverse_doubly(head);

    cout<<endl;

    return 0;


}