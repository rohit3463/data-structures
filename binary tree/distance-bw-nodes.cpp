#include<iostream>
#include<string>
#include<unordered_set>

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
void find_level(node * root,int n1,int n2,int index,int& level1,int& level2)
{
	if(root == nullptr)
	{
		return;
	}

	if(root->data == n1)
	{
		level1 = index;
	}
	if(root->data == n2)
	{
		level2 = index;
	}

	find_level(root->left,n1,n2,index+1,level1,level2);
	find_level(root->right,n1,n2,index+1,level1,level2);

}

node * find_LCA(node * root,int index,int n1,int n2,int& level_n1,int& level_n2)
{
	if(root == nullptr)
	{
		return nullptr;
	}

	if(root->data == n1)
	{
		level_n1 = index;
		return root;
	}
	if(root->data == n2)
	{
		level_n2 = index;
		return root;
	}

	node * left = find_LCA(root->left,index+1,n1,n2,level_n1,level_n2);
	node * right = find_LCA(root->right,index+1,n1,n2,level_n1,level_n2);

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

int distance_bw_nodes(node * LCA,int n1,int n2)
{
	int level_n1,level_n2;

	find_level(LCA,n1,n2,0,level_n1,level_n2);

	return level_n1 + level_n2 ;
}

int  main()
{
	node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->left->right->left = newNode(7);


    int n1,n2,level_n1,level_n2;

    n1 = 7;
    n2 = 6;

    node * LCA = find_LCA(root,0,n1,n2,level_n1,level_n2);

    //cout<<LCA->data<<endl<<distance_bw_nodes(LCA,n1,n2)<<endl;

    cout<<(level_n1+level_n2)<<endl;




}