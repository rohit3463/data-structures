/*
source :- https://www.geeksforgeeks.org/construct-full-binary-tree-using-preorder-traversal-preorder-traversal-mirror-tree/
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

int p[] = {1,2,4,8,9,5,3,6,7};
int pm[] = {1,3,7,6,2,5,4,9,8};

mytree * maketree(int p_start,int p_end,int pm_start,int pm_end)
{
	if(p_start <= p_end && pm_start <= pm_end)
	{
		mytree * root = constr(p[p_start]);

		if(p_start != p_end && pm_start != pm_end)
		{
			int right_root,left_root;

			for(int i = p_start+1;i<=p_end;i++)
			{
				if(p[i] == pm[pm_start + 1])
				{
					right_root = i;

					break;
				}
			}
			for(int i = pm_start+1;i<=pm_end;i++)
			{
				if(pm[i] == p[p_start + 1])
				{
					left_root = i;

					break;
				}
			}

			root->left = maketree(p_start+1,right_root-1,left_root,pm_end);
			root->right = maketree(right_root,p_end,pm_start+1,left_root-1);
		}
		return root;
	}
	return nullptr;
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
	mytree * root = maketree(0,sizeof(p)/sizeof(int)-1,0,sizeof(pm)/sizeof(int)-1);

	inorder_traverse(root);

	cout<<endl;

	return 0;
}