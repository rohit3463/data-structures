#include<iostream>

using namespace std;

int preorder[] = {10,30,20,5,15};
int describe[] = {'N','N','L','L','L'};

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

mytree * maketree()
{
	static int index = 0;

	if(index>sizeof(preorder)/sizeof(int)-1)
	{
		return nullptr;
	}
	if(describe[index] == 'L')
	{
		mytree * temp = constr(preorder[index]);

		return temp;
	}
	else if(describe[index] == 'N')
	{
		mytree * temp = constr(preorder[index]);

		index++;

		temp->left = maketree();

		index++;

		temp->right = maketree();

		return temp;
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
	mytree * root = maketree();

	inorder_traverse(root);

	cout<<endl;
	


}