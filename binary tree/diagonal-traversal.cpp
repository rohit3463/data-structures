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
void diagonal_traverse(mytree * root)
{
	mytree * node = root ;

	queue < mytree * > diagonal_queue;

	if(node == nullptr)
	{
		return;
	}

	diagonal_queue.push(node);

	while(node->right_node != nullptr)
	{
		diagonal_queue.push(node->right_node);

		node = node->right_node;
	}
	while(!diagonal_queue.empty())
	{
		node = diagonal_queue.front();

		diagonal_queue.pop();

		cout<<node->data<<" ";

		if(node->left_node != nullptr)
		{
			node = node->left_node;
			
			diagonal_queue.push(node);

			while(node->right_node != nullptr)
			{
				diagonal_queue.push(node->right_node);

				node = node->right_node;
			}
		}
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

	diagonal_traverse(root);


	return 0;
}