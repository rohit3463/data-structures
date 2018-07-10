#include<iostream>
#include<climits>
#include<algorithm>

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

void printvec(int start,vector< int > path)
{
	for(int i=start;i<path.size();i++)
	{
		cout<<path[i]<<" ";
	}
	cout<<endl;
}


void K_sum_paths(node * root,vector< int >& path,int K)
{
	if(root == nullptr)
	{
		return;
	}

	path.push_back(root->data);

	K_sum_paths(root->left,path,K);

	K_sum_paths(root->right,path,K);

	int sum =0;

	for(int i=path.size()-1;i>-1;i--)
	{
		sum += path[i];

		if(sum == K)
		{
			printvec(i,path);
		}
	}

	path.pop_back();
}

int main()
{
	node *root = newNode(1);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(1);
    root->right = newNode(-1);
    root->right->left = newNode(4);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(2);
    root->right->right = newNode(5);
    root->right->right->right = newNode(2);
 
    int k = 5;

    vector < int > path;

    K_sum_paths(root,path,k);
	return 0;
}