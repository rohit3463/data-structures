#include<iostream>
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

int height_and_size(node * root,int& size)
{
	if(root == nullptr)
	{
		return 0;
	}

	int left = height_and_size(root->left,size);

	size++;

	int right = height_and_size(root->right,size);

	
	return max(left,right) + 1;


}

float density_binarytree(node * root)
{
	static int size = 0;

	if(root == nullptr)
	{
		return 0;
	}

	int height = height_and_size(root,size);

	return height/(float)size;
}

int main()
{

	float density;

	struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);

    density = density_binarytree(root);
	cout<<density<<endl;



	return 0;
}