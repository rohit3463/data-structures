#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

struct node
{
	int data;

	node * left = nullptr;

	node * right = nullptr;
};

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

vector < node * > print_all_preorder(int arr[],int start,int end)
{
	vector < node * > trees;
	if(start>end)
	{
		trees.push_back(nullptr);
		return trees;
	}

	for(int i=start ; i<=end ; i++)
	{
		vector < node * > ltrees = print_all_preorder(arr,start,i-1);
		vector < node * > rtrees = print_all_preorder(arr,i+1,end);

		for(int j = 0;j<ltrees.size();j++)
		{
			for(int k=0;k<rtrees.size();k++)
			{
				node * hello = new node;

				hello->data  = arr[i];

				hello->left = ltrees[j];

				hello->right = rtrees[k];

				trees.push_back(hello);
			}
		}
	}

	return trees;
} 
int main()
{
	int arr[] = {4,5,7};

	vector < node * > trees;

	trees = print_all_preorder(arr,0,2);

	for(auto& y: trees)
	{
		preorder(y);
		cout<<endl;
	}

	return 0;
}