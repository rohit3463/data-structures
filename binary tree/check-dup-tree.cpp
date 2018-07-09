#include<iostream>
#include<string>
#include<unordered_set>

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

unordered_set < string > check;


string duptree(node * root)
{
	if(root == nullptr)
	{
		return "$";
	}
	string s = "";

	string ltree = duptree(root->left);

	if(ltree == "")
	{
		return "";
	}

	string rtree = duptree(root->right);

	if(rtree == "")
	{
		return "";
	}

	s = root->data + ltree + rtree;

	if(check.find(s) != check.end() && s.length() > 3)
	{
		return "";
	}
	else
	{
		check.insert(s);
	}

	return s;
}
bool checkduptree(node * root)
{
	if(duptree(root) == "")
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
	node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('B');
    root->right->right->right = newNode('E');
    root->right->right->left= newNode('D');

    if(checkduptree(root))
    {
    	cout<<"YES"<<endl;
    }
    else
    {
    	cout<<"NO"<<endl;
    }
 

	return 0;
}