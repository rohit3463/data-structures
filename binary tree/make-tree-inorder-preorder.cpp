/*
source - https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
*/
#include<iostream>

using namespace std;

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
mytree * make_tree(int inorder[], int preorder[], int start, int end )
{
	static int index = 0;

	int root_index;

	if(start<end)
	{
		for(int i=start;i<=end;i++)
		{
			if(inorder[i] == preorder[index])
			{
				root_index = i;
				break;
			}
		}
		mytree * root = constr(inorder[root_index]);

		if(start<=(root_index-1))
		{

			index++;

			root->left = make_tree(inorder,preorder,start,root_index-1);
		}
		if((root_index+1)<=end)
		{
			index++;

			root->right = make_tree(inorder,preorder,root_index+1,end);
		}

		return root;
	}
	else if(start == end)
	{
		mytree * root = constr(inorder[start]);

		return root;
	}
	else
	{
		return nullptr;
	}
}
void inorder_traverse(mytree * root)
{
	if(root == nullptr)
	{
		return;
	}

	inorder_traverse(root->left);

	cout<<root->data<<" ";

	inorder_traverse(root->right);
}

int main()
{
	//int inorder[5] = {4,2,5,1,3};

	//int preorder[5] = {1,2,4,5,3};

	int inorder[] = {9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7};
    int preorder[] = {1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13};

	mytree * root = make_tree(inorder,preorder,0,sizeof(preorder)/sizeof(int)-1);

	inorder_traverse(root);


}
