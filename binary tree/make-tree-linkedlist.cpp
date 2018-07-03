#include<iostream>
#include<queue>
#include<list>
#include<iterator>

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

mytree * maketree(list < int >& mylist)
{
	list < int >::iterator it = mylist.begin();

	queue < mytree * > myqueue;

	mytree * root = constr(*it);
	mytree * temp;

	myqueue.push(root);

	it++;



	while(it != mylist.end())
	{
		temp = myqueue.front();
		myqueue.pop();

		

		if(it != mylist.end())
		{

			temp->left = constr(*it);

			myqueue.push(temp->left);

			it++;
		}
		
		if(it != mylist.end())
		{

			temp->right = constr(*it);

			myqueue.push(temp->right);

			it++;
		}
	}

	return root;
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
	list < int > mylist;

	mylist.push_front(36);

	mylist.push_front(30);

	mylist.push_front(25);

	mylist.push_front(15);

	mylist.push_front(12);

	mylist.push_front(10);

	//mylist.push_back(35);

	mytree * root = maketree(mylist);

	inorder_traverse(root);

	cout<<endl;

	return 0;

}