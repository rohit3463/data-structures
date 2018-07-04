#include<iostream>
#include<list>

using namespace std;

struct mytree
{
	int data;

	mytree * left = nullptr;

	mytree * middle = nullptr;

	mytree * right = nullptr;
};

struct mytree * newNode(int key)
{
	mytree * temp = new mytree;

	temp->data = key;

	temp->left = nullptr;

	temp->middle = nullptr;

	temp->right = nullptr;

	return temp;
}

void make_list(mytree * root,list < int >& doubly)
{
	if(root == nullptr)
	{
		return;
	}
	doubly.push_back(root->data);

	make_list(root->left,doubly);

	make_list(root->middle,doubly);

	make_list(root->right,doubly);
}

int main()
{
	list < int > doubly;

	mytree * root = newNode(1);

	root->left = newNode(5);
    root->middle = newNode(11);
    root->right = newNode(63);
 
    root->left->left = newNode(1);
    root->left->middle = newNode(4);
    root->left->right = newNode(8);
 
    root->middle->left = newNode(6);
    root->middle->middle = newNode(7);
    root->middle->right = newNode(15);
 
    root->right->left = newNode(31);
    root->right->middle = newNode(55);
    root->right->right = newNode(65);

    make_list(root,doubly);

    for(auto& y:doubly)
    {
    	cout<<y<<" ";
    }

    cout<<endl;

}