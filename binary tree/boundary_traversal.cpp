/*
source - https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
*/
#include<iostream>
#include<queue>
#include<stack>
#include<climits>

using namespace std;

struct mytree
{
	int data;
	mytree * left_node = nullptr;
	mytree * right_node = nullptr;
};
struct mytree * constr(int key)
{
	mytree * temp = new mytree;

	temp->data = key;

	temp->left_node = nullptr;
	temp->right_node = nullptr;

	return temp;
}

void print_all_leafs(mytree * root)
{
	if(root != nullptr)
	{
		print_all_leafs(root->left_node);

		if(root->left_node == nullptr && root->right_node == nullptr)
		{
			cout<<root->data<<" ";
		}

		print_all_leafs(root->right_node);
	}
}

void boundary_traverse(mytree * root)
{
	mytree * temp = root;

	stack < mytree * > right_stack;

	if(temp->left_node == nullptr)
	{
		cout<<temp->data<<" ";
	}

	if(temp->left_node != nullptr)
	{
		cout<<temp->data<<" ";

		while(temp->left_node->left_node != nullptr)
		{
			temp = temp->left_node;

			cout<<temp->data<<" ";
		} 
		temp = root;
	}

	print_all_leafs(temp);

	temp = root;

	if(temp->right_node != nullptr)
	{
		while(temp->right_node->right_node != nullptr)
		{
			temp = temp->right_node;

			right_stack.push(temp);
		}

			
	}

	while(!right_stack.empty())
	{
		cout<<right_stack.top()->data<<" ";

		right_stack.pop();
	}


}

int main()
{
	mytree * root = constr(1);

	root->left_node = constr(2);

	root->left_node->left_node = constr(3);

	root->left_node->left_node->left_node = constr(4);

	root->left_node->left_node->left_node->left_node = constr(5);

	root->right_node = constr(6);

	root->right_node->left_node = constr(4);

	root->right_node->left_node->left_node = constr(8);

	root->right_node->left_node->left_node->right_node  = constr(11);

	root->right_node->left_node->right_node = constr(10);

	root->right_node->right_node = constr(7);

	root->right_node->right_node->right_node = constr(9);

	
	boundary_traverse(root);


	return 0;
}