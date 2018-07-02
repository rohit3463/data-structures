/*
source - https://www.geeksforgeeks.org/level-order-tree-traversal/
*/
#include<iostream>
#include<queue>
#include<stack>
#include<climits>

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
	void levelordertraverse_byline()
	{
		queue < mytree * > temp;
		mytree * it = this ;
		mytree * last = new mytree(INT_MIN);
		mytree * nuller = new mytree(INT_MIN);
		temp.push(nuller);

		while(it != nullptr)
		{

			if(it->left_node != nullptr)
			temp.push(it->left_node);
			if(it->right_node != nullptr)
			temp.push(it->right_node);
		    if(it->data == INT_MIN)
			{
				cout<<endl;
				temp.push(nuller);
			}
			else
			{
				cout<<it->data<<" ";
			}
			if(temp.empty())
			{
				return;
			}
			last = it;
			it = temp.front();
			if(last->data == INT_MIN && it->data == INT_MIN)
			{
				return;
			}
			temp.pop();
		}
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

	obj->levelordertraverse();
	cout<<endl;

	cout<<endl;

	obj->levelordertraverse_byline();


	return 0;
}