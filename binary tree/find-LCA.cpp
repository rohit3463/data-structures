#include<iostream>
#include<climits>

using namespace std;

struct node 
{
	int data;
	node * left = nullptr;
	node * right = nullptr;
};

struct node * newNode(char key)
{
	node * temp = new node;

	temp->data = key;
	temp->left = nullptr;
	temp->right= nullptr;

	return temp;
}

node * find_LCA(node * root,int n1,int n2)
{
	if(root == nullptr)
	{
		return nullptr;
	}

	if(root->data == n1 || root->data == n2)
	{
		return root;
	}

	node * left = find_LCA(root->left,n1,n2);
	node * right = find_LCA(root->right,n1,n2);

	if(left != nullptr && right != nullptr)
	{
		return root;
	}

	if(left != nullptr)
	{
		return left;
	}
	else
	{
		return right;
	}
}

int main()
{
	node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << find_LCA(root, 4, 5)->data<<endl;
    cout << "LCA(4, 6) = " << find_LCA(root, 4, 6)->data<<endl;
    cout << "LCA(3, 4) = " << find_LCA(root, 3, 4)->data<<endl;
    cout << "LCA(2, 4) = " << find_LCA(root, 2, 4)->data<<endl;

    return 0;
}