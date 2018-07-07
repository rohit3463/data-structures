#include<iostream>
#include<queue>

using namespace std;

struct node 
{
	int data;
	node * left = nullptr;
	node * right = nullptr;
};

struct node * newNode(int key)
{
	node * temp = new node;

	temp->data = key;
	temp->left = nullptr;
	temp->right= nullptr;

	return temp;
}

bool perfect_binary_tree(node * root)
{
	queue < node * > temp;
	queue < node * > temp1;
	node * it = nullptr;
	int flag =0;

	temp.push(root); 

	while(!temp.empty() || !temp1.empty())
	{
		while(!temp.empty())
		{
			it = temp.front();
			temp.pop();

			if(it->left != nullptr && it->right != nullptr)
			{
				if(flag==0)
				{
					temp1.push(it->left);
					temp1.push(it->right);
				}
				else
				{
					return false;
				}
			}
			else if(it->left != nullptr || it->right != nullptr)
			{
				return false;
			}
			else
			{
				flag = 1;
			}
		}
		if(flag == 1)
		{
			break;
		}
		while(!temp1.empty())
		{
			it = temp1.front();
			temp1.pop();

			if(it->left != nullptr && it->right != nullptr)
			{
				if(flag==0)
				{
					temp.push(it->left);
					temp.push(it->right);
				}
				else
				{
					return false;
				}
			}
			else if(it->left != nullptr || it->right != nullptr)
			{
				return false;
			}
			else
			{
				flag = 1;
			}
		}
		if(flag==1)
		{
			break;
		}
	}


	if(temp.empty() && temp1.empty())
		return true;
	else
		return false;
}

int main()
{
	struct node* root = NULL;
    root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
 
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    //root->right->left = newNode(60);
    //root->right->right = newNode(70);

    if(perfect_binary_tree(root))
    {
    	cout<<"YES"<<endl;
    }
    else
    {
    	cout<<"NO"<<endl;
    }

    return 0;
}