#include<iostream>
#include<stack>
#include<cctype>
#include<queue>
#include<sstream>

using namespace std;

struct exp_tree
{
	exp_tree * left = nullptr;
	exp_tree * right = nullptr;
	char data; 
};

exp_tree * make_exptree(string s)
{
	stringstream r(s);
	stack < exp_tree * > stack_exp;
	char ch;
	exp_tree * temp = nullptr;

	while(r >> ch)
	{
		temp = new exp_tree;
		if(isdigit(ch))
		{
			temp->data = ch;
			stack_exp.push(temp);
		}
		else
		{
			temp->right = stack_exp.top();
			stack_exp.pop();
			temp->left = stack_exp.top();
			stack_exp.pop();
			temp->data = ch;

			stack_exp.push(temp);

		}
	}

	return stack_exp.top();
}
void inorder_traverse(exp_tree * root)
	{
		if(root == nullptr)
			return;

		inorder_traverse(root->left);

		cout<<root->data<<" ";

		inorder_traverse(root->right);

		return;
	}

int main()
{
	exp_tree * root = nullptr;

	root = make_exptree("12+23*4*-");

	inorder_traverse(root);
}