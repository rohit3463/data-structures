#include<iostream>
#include<queue>

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
			temp.push(it->left_node);
			temp.push(it->right_node);

			it = temp.front();
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
				temp.push(it->left_node);
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

	return 0;
}