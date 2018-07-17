#include<iostream>

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
	temp->right = nullptr;

	return temp;
}

node * insert(node * root,int key)
{
	if(root == nullptr)
	{
		return newNode(key);
	}

	if(key < root->data)
	{
		root->left = insert(root->left,key);
	}
	else if(key > root->data)
	{
		root->right = insert(root->right,key);
	}

	return root;
}
node * minValueNode(node* node)
{
    struct node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

node * deleteNode(node * root,int key)
{
	if(root == nullptr)
	{
		return root;
	}

	if(key < root->data)
	{
		root->left = deleteNode(root->left,key);
	}

	else if(key > root->data)
	{
		root->right = deleteNode(root->right,key);
	}
	
	else
	{
		if(root->left == nullptr)
		{
			node * temp = root->right;
			delete root;

			return temp;
		}
		else if(root->right == nullptr)
		{
			node * temp = root->left;
			delete root;

			return temp;
		}

		node * temp = minValueNode(root->right);

		root->data = temp->data;


		root->right = deleteNode(root->right,temp->data);

	}

	return root;
}

node * search(node * root,int key)
{
	if(root == nullptr || root->data == key)
	{
		return root;
	}

	if(key>root->data)
	{
		return search(root->right,key);
	}

	return search(root->left,key);
}

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

int main()
{
	node * root = nullptr;

	root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    preorder(root);

    cout<<endl;

    if(search(root,70) != nullptr)
    {
    	cout<<"YES";
    }
    else
    {
    	cout<<"NO";
    }

    root = deleteNode(root,70);

    cout<<endl;

    if(search(root,70) != nullptr)
    {
    	cout<<"YES";
    }
    else
    {
    	cout<<"NO";
    }



    cout<<endl;

    preorder(root);

    cout<<endl;



	return 0;
}