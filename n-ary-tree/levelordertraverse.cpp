#include<iostream>
#include<queue>

using namespace std;

const int N= 10;

class Node
{
public:
	char data;
	Node * child[N];

	Node(char data)
	{
		this->data = data;
		for(int i=0;i<N;i++)
		{
			child[i] = nullptr;
		}
	}
};

void levelordertraverse(Node * root)
{
	queue < Node * > temp;
	Node * it = root;

	temp.push(it);

	while(!temp.empty())
	{
		it = temp.front();

		cout<<it->data<<" ";

		temp.pop();

		for(int i =0;i<N;i++)
		{
			if(it->child[i] != nullptr)
			{
				temp.push(it->child[i]);
			}
		}
	}
}


int main()
{
	Node *root = new Node('A');
    root->child[0] = new Node('B');
    root->child[1] = new Node('C');
    root->child[2] = new Node('D');
    root->child[3] = new Node('E');
    root->child[0]->child[0] = new Node('F');
    root->child[0]->child[1] = new Node('G');
    root->child[2]->child[0] = new Node('H');
    root->child[0]->child[0]->child[0] = new Node('I');
    root->child[0]->child[0]->child[1] = new Node('J');
    root->child[0]->child[0]->child[2] = new Node('K');
    root->child[2]->child[0]->child[0] = new Node('L');
    root->child[2]->child[0]->child[1] = new Node('M');

    levelordertraverse(root);

    cout<<endl;
 

	return 0;
}