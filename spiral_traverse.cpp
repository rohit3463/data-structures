#include<iostream>
#include<stack>

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
void spiral_traverse(node * root)
{
	stack < node * > left_right;
	stack < node * > right_left;

	left_right.push(root);

	while(!left_right.empty() || !right_left.empty())
	{
		while(!left_right.empty())
		{
			cout<<left_right.top()->data<<" ";

			if(left_right.top()->right != nullptr)
			{
				right_left.push(left_right.top()->right);
			}
			if(left_right.top()->left != nullptr)
			{
				right_left.push(left_right.top()->left);
			}

			left_right.pop();
		}
		while(!right_left.empty())
		{
			cout<<right_left.top()->data<<" ";

			if(right_left.top()->left != nullptr)
			{
				left_right.push(right_left.top()->left);
			}
			if(right_left.top()->right != nullptr)
			{
				left_right.push(right_left.top()->right);
			}

			right_left.pop();
		}
	}
}
int main()
{

	node * root = constr(1);

	root->left = constr(2);

	root->right = constr(3);

	root->left->left = constr(7);

	root->left->right = constr(6);

	root->right->left = constr(5);

	root->right->right = constr(4);

	spiral_traverse(root);


	return 0;
}