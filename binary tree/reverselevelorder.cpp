/*
source - https://www.geeksforgeeks.org/reverse-level-order-traversal/
*/
#include<iostream>
#include<queue>
#include<stack>

using namespace std;
class mytree
{
private:
	mytree * left_node;
	int data;
	mytree * right_node;
public:
	mytree(int value)
	{
		this->data = value;
		this->left_node = nullptr;
		this->right_node = nullptr;
	}
	mytree *& left()
	{
		return this->left_node;
	}
	mytree *& right()
	{
		return this->right_node;
	}
	void print()
	{
		cout<<this->data<<" ";
	}
	void insert_node(int taken)
	{
		queue < mytree * > temp;
		mytree * it = this ;

		while(it != nullptr)
		{
			if(it->left_node == nullptr)
			{
				it->left_node = new mytree(taken);
				return;
			}
			else if (it->right_node == nullptr)
			{
				it->right_node = new mytree(taken);
				return;
			}
			else
			{
				if(it->left_node != nullptr)
				temp.push(it->left_node);
				if(it->right_node != nullptr)
				temp.push(it->right_node);

				it = temp.front();
				temp.pop();
			}
		}
	}
	void delete_node()
	{
		queue < mytree * > temp;
	    mytree *it = this, *parent = nullptr;

		while(it != nullptr)
		{
			
			if(it->left_node != nullptr) {
				temp.push(it->left_node);
				parent = it;
			}
			if(it->right_node != nullptr){
				temp.push(it->right_node);
				parent = it;
			}

			it = temp.front();
			temp.pop();
		}
		if(parent->right_node != nullptr) {
			it = parent->right_node;
			parent->right_node = nullptr;
			delete it;
		}
		else {
			it = parent->left_node;
			parent->left_node = nullptr;
			delete it;
		}
	}
	void levelordertraverse()
	{
		queue < mytree * > temp;
		mytree * it = this ;

		while(it != nullptr)
		{
			cout<<it->data<<" ";
			if(it->left_node != nullptr)
			temp.push(it->left_node);
			if(it->right_node != nullptr)
			temp.push(it->right_node);
			if(temp.empty())
			{
				return;
			}
			it = temp.front();
			temp.pop();
		}
	}
	void reverselevelorder()
	{
		stack < mytree * > temp;

		queue < mytree * > q;

		mytree * it = this ;

		temp.push(it);

		while(it != nullptr)
		{
			if(it->right_node != nullptr)
			q.push(it->right_node);
			if(it->left_node != nullptr)
			q.push(it->left_node);

			if(q.empty())
			{
				break;
			}
			it = q.front();

			q.pop();

			temp.push(it);
		}
		while(!temp.empty())
		{
			cout<<temp.top()->data<<" ";

			temp.pop();
		}
		cout<<endl;
	}

};

int main()
{
	mytree * obj = new mytree(1);

	obj->insert_node(2);
	obj->insert_node(3);
	obj->insert_node(4);
	obj->insert_node(5);
	obj->insert_node(6);
	obj->insert_node(7);

	obj->delete_node();

	obj->levelordertraverse();

	cout<<endl;

	obj->reverselevelorder();

	return 0;
}