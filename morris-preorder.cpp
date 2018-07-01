#include<iostream>
#include<vector>

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

void morris(node * root)
{
	while(root != nullptr)
	{
		if(root->left == nullptr)
		{
			cout<<root->data<<" ";
			root = root->right;
		}
		else
		{
			node * current = root->left;

			while(current->right!=root && current->right != nullptr)
			{
				current = current->right;
			}

			if(current->right == root)
			{
				current->right = nullptr;
				root = root->right;
			}
			else
			{
				cout<<root->data<<" ";
				current->right = root;
				root = root->left;
			}
		}
	}
}

int main()
{

	node * root = constr(1);

	root->left = constr(2);

	root->right = constr(3);

	root->left->left = constr(4);

	root->left->right = constr(5);

	root->right->left = constr(8);

	root->right->right = constr(9);

	root->left->right->left = constr(6);

	root->left->right->right = constr(7);



	morris(root);

	return 0;

}