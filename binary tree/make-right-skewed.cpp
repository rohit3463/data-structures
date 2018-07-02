/*
source - https://www.geeksforgeeks.org/modify-binary-tree-get-preorder-traversal-using-right-pointers/
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

void modifytree(mytree * root)
{
	if(root != nullptr)
	{
		modifytree(root->right_node);
		modifytree(root->left_node);

		if(root->left_node != nullptr)
		{
			mytree * lp = root->left_node;

			mytree * rp = root->right_node;

			root->left_node = nullptr;

			root->right_node = lp;

			while(lp->right_node != nullptr)
			{
				lp = lp->right_node;
			}

			lp->right_node = rp;
		}
	}
}
void traverse(mytree * root)
{
	if(root == nullptr)
	{
		return;
	}
	cout<<root->data<<" ";

	traverse(root->right_node);
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

	
	modifytree(root);

	traverse(root);

	return 0;
}