#include<iostream>
#include<stack>

using namespace std;

struct node{
  int data;
  node *left, *right;
};

struct node* newNode(int data){
  struct node *Node = new node;
  Node->data = data;
  Node->left= nullptr;
  Node->right = nullptr;

  return Node;
}

void make_doubly_spiral(node * root)
{
	stack < node * > left;
	stack < node * > right;

	left.push(root);

	node * l_last = nullptr;
	node * r_last = nullptr;
	node * l_front = nullptr;
	node * r_front = nullptr;
	

	while(!left.empty() || !right.empty())
	{
		node * last_popped  =nullptr;
		if(!left.empty())
		{
			l_front = left.top();
		
			while(!left.empty())
			{
				l_last = left.top();
				left.pop();

				if(l_last->right != nullptr)
				{
					right.push(l_last->right);
				}
				if(l_last->left != nullptr)
				{
					right.push(l_last->left);
				}
				if(last_popped == nullptr)
				{
					last_popped = l_last;
				}
				else
				{
					l_last->left = last_popped;
					last_popped->right = l_last;
					last_popped = l_last;
				}
			}
			if(r_last != nullptr)
			{
				r_last->right = l_front;
				l_front->left = r_last;
			}
			else
			{
				l_front->left = nullptr;
			}
			
		}
		last_popped  =nullptr;
		if(!right.empty())
		{
			r_front = right.top();
		
			while(!right.empty())
			{
				r_last = right.top();

				right.pop();

				if(r_last->left != nullptr)
				{
					left.push(r_last->left);
				}
				if(r_last->right != nullptr)
				{
					left.push(r_last->right);
				}
				if(last_popped == nullptr)
				{
					last_popped = r_last;
				}
				else
				{
					last_popped->right = r_last;
					r_last->left = last_popped;
					last_popped = r_last;
				}
			}
			l_last->right = r_front;
			r_front->left = l_last;
		}
	}

}

void traverse_doubly(node * head)
{
	if(head==nullptr)
	{
		return;
	}
	while(head != nullptr)
	{
		cout<<head->data<<" ";
		head = head->right;
	}
}

int main()
{
	struct node *root  = newNode(10);
    root->left         = newNode(8);
    root->right        = newNode(2);
    root->left->left   = newNode(3);
    //root->left->right  = newNode(5);
    root->right->right = newNode(6);
    root->right->left  = newNode(4);

    make_doubly_spiral(root);

    traverse_doubly(root);

    cout<<endl;


	return 0;
}