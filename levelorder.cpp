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

	obj->left() = new mytree(2);

	obj->right() = new mytree(3);

	obj->levelordertraverse();

	return 0;
}