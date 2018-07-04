#include<iostream>
#include<unordered_map>
#include<utility>

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
int N = 6;
int mat[6][6] = {{ 0, 0, 0, 0, 0, 0 },
       		     { 1, 0, 0, 0, 1, 0 },
        		 { 0, 0, 0, 1, 0, 0 },
        		 { 0, 0, 0, 0, 0, 0 },
       		 	 { 0, 0, 0, 0, 0, 0 },
       			 { 1, 1, 1, 1, 1, 0 }};

mytree * maketree()
{
	unordered_map < int , pair < mytree * , bool > > m;

	pair < mytree * , bool > temp;
	mytree * root = nullptr;

	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			
			if(mat[i][j])
			{
				if(m.find(j) != m.end())
				{
					if(m[j].second == false)
					{
						if(m.find(i) != m.end())
						{
							if(m[i].first->left == nullptr)
							{
								m[i].first->left = m[j].first;
								m[j].second = true;
							}
							else if(m[i].first->right == nullptr)
							{
								m[i].first->right = m[j].first;
								m[j].second = true;
							}
						}
						else
						{
							mytree * node = constr(i);

							node->left = m[j].first;

							m[i] = make_pair(node,false);

							root = node;
						}
					}

				}
				else
				{
					if(m.find(i) != m.end())
					{
						if(m[i].first->left == nullptr)
							{
								m[i].first->left = constr(j);
								m[j] = make_pair(m[i].first->left,true);
							}
						else if(m[i].first->right == nullptr)
							{
								m[i].first->right = constr(j);
								m[j] = make_pair(m[i].first->right,true);
							}
					}
					else
					{
						mytree * node = constr(i);

						node->left = constr(j);

						m[i] = make_pair(node,false);
						m[j] = make_pair(m[i].first->left,true);

						root = node;
					}
				}
			}
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
	mytree * root = maketree();

	inorder_traverse(root);

	cout<<endl;
}