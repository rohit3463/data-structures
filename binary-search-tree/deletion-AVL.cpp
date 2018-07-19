#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
	int data;
	node * left = nullptr;
	node * right = nullptr;
	int height;
};

struct node * newNode(int key)
{
	node * temp = new node;
	temp->data = key;
	temp->height = 1;

	return temp;
}
int height(node * root)
{
	if(root == nullptr)
	{
		return 0;
	}
	return root->height;
}
node * leftRotate(node * z)
{
	node * y = z->right;
	node * t2 = y->left;

	y->left = z;
	z->right = t2;

	z->height = max(height(z->left),height(z->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	return y;
}
node * rightRotate(node * z)
{
	node * y = z->left;
	node * t2 = y->right;

	y->right = z;
	z->left = t2;

	z->height = max(height(z->left),height(z->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	return y;

}

int getBalance(node * root)
{
	if(root == nullptr)
	{
		return 0;
	}
	return height(root->left) - height(root->right);
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

	else return root;

	root->height = max(height(root->left),height(root->right)) + 1;

	int balance = getBalance(root);

	if(balance < -1)
	{
		if(key > root->right->data)
		{
			return leftRotate(root);
		}
		else if(key < root->right->data)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	else if(balance > 1)
	{
		if(key > root->left->data)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		else if(key < root->left->data)
		{
			return rightRotate(root);
		}
	}

	return root;
}
node * minValueNode(node* node)
{
    struct node* current = node;
 
    while (current->left != nullptr)
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

	if(root == nullptr)
	{
		return root;
	}
	root->height = max(height(root->left),height(root->right)) + 1;

	int balance = getBalance(root);

	if(balance > 1)
	{
		if(getBalance(root->left) >= 0)
		{
			return rightRotate(root);
		}
		else if(getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);

			return rightRotate(root);
		}
	}
	else if(balance < -1)
	{
		if(getBalance(root->right) <= 0)
		{
			return leftRotate(root);
		}
		else if(getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);

			return leftRotate(root);
		}
	}
	return root;


}


void inorder(node * root)
{
	if(root == nullptr)
	{
		return;
	}

	inorder(root->left);

	cout<<root->data<<" ";

	inorder(root->right);
}


int main()
{
	node *root = nullptr;
	root = insert(root, 10);
	root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
 

	inorder(root);

	cout<<endl;

	root = deleteNode(root,10);

	inorder(root);

	cout<<endl;
 


    return 0;


}