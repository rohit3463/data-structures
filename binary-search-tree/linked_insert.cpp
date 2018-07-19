#include<iostream>
#include<list>

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

node * linked_insert(auto& it,int n)
{
	if(n<=0)
	{
		return nullptr;
	}

	node * left_temp = linked_insert(it,n/2);

	node * root = newNode(*it);

	root->left = left_temp;

	it++;

	root->right = linked_insert(it,n-n/2-1);

	return root;
}

void preorder(node * root)
{
	if(root == nullptr)
	{
		return;
	}
	cout<<root->data<<" ";

	preorder(root->left);

	preorder(root->right);
}


int main()
{

	list < int > hello {1,2,3,4,5,6,7};

	auto it = hello.begin();

	node * root = linked_insert(it,hello.size());

	preorder(root);

	cout<<endl;

	return 0;
}