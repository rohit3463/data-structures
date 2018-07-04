#include<iostream>
#include<vector>

using namespace std;

vector< vector < int > > arr(6, vector< int > (6, 0));

struct mytree
{
	int data;

	mytree * left = nullptr;

	mytree * right = nullptr;
};

struct mytree * constr(int key)
{
	mytree * temp = new mytree;

	temp->data = key;

	temp->left = nullptr;

	temp->right = nullptr;

	return temp;
}
void ancestor_matrix(mytree * root,int N)
{
	if(root == nullptr)
	{
		return;
	}

	ancestor_matrix(root->left,N);

	ancestor_matrix(root->right,N);

	if(root->left != nullptr)
	{
		arr[root->data][root->left->data] = 1;

		for(int i=0;i<=N;i++)
		{
			if(arr[root->left->data][i] == 1)
			{
				arr[root->data][i] = 1;
			}
		}
	}
	if(root->right != nullptr)
	{
		arr[root->data][root->right->data] = 1;

		for(int i=0;i<=N;i++)
		{
			if(arr[root->right->data][i] == 1)
			{
				arr[root->data][i] = 1;
			}
		}
	}
}

int main()
{
	mytree * root = constr(5);

	root->left = constr(1);
	root->right = constr(2);

	root->left->left = constr(0);
	root->left->right = constr(4);

	root->right->left = constr(3);

	ancestor_matrix(root,5);

	for(int i=0;i<=5;i++)
	{
		for(int j=0;j<=5;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}



