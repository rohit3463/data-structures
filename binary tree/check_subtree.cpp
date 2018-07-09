#include<iostream>
#include<string>

using namespace std;

struct node 
{
	char data;
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

void inorder(node * root,string& str)
{
	if(root==nullptr)
	{
		str.push_back('$');
		return;
	}
	inorder(root->left,str);

	str.push_back(root->data);

	inorder(root->right,str);
}

void preorder(node * root,string& str)
{
	if(root == nullptr)
	{
		str.push_back('$');
		return;
	}

	str.push_back(root->data);

	preorder(root->left,str);

	preorder(root->right,str);

}

bool check_subtree(node * root,node * sub_root)
{
	string pre_root,in_root,pre_sub_root,in_sub_root;

	inorder(root,in_root);

	preorder(root,pre_root);

	inorder(sub_root,in_sub_root);

	preorder(sub_root,pre_sub_root);

	if(in_root.find(in_sub_root) != string::npos && pre_root.find(pre_sub_root) != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	node *T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    node *S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');

    if(check_subtree(T,S))
    {
    	cout<<"YES"<<endl;
    }
    else
    {
    	cout<<"NO"<<endl;
    }

    return 0;
}