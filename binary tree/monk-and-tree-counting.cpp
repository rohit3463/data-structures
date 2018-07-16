#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

struct node 
{
    long long data;
    node * left = nullptr;
    node * right = nullptr;
};
struct node * newNode(long long key)
{
    node * temp = new node;
    temp->data = key;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

unordered_map < long long , node * > hello;

vector < long long > input_vector;

long long count =0;

void preorder_2(node * root,long long K,node * orig1,node * orig2)
{
  if(root == nullptr)
  {
    return;
  }

  if(root != orig1 && root != orig2 && root->data >= K)
  {
    count++;
  }
  if(root->left)
  preorder_2(root->left,K,orig1,orig2);
  if(root->right)
  preorder_2(root->right,K,orig1,orig2);
}
void preorder_1(node * root,long long K,node * orig)
{
  if(root == nullptr)
  {
    return;
  }
  if(root!= orig)
  {
    preorder_2(orig,K-root->data,orig,root);
  }

  preorder_1(root->left,K,orig);
  preorder_1(root->right,K,orig);
}
void preorder(node * root,long long K)
{
  if(root == nullptr)
  {
    return;
  }
  preorder_1(root, K-root->data, root);
  preorder(root->left, K);
  preorder(root->right, K);
}
int main()
{
  long long N,K,temp;
  cin>>N;
  cin>>K;

  for(long long i=0;i<N;i++)
  {
    cin>>temp;
    input_vector.push_back(temp);

    hello[i+1] = newNode(temp);
  }

  for(long long i=1;i<N;i++)
  {
    cin>>temp;
    if(hello[temp]->left == nullptr)
    {
      hello[temp]->left = hello[i+1];
    }
    else if(hello[temp]->right == nullptr)
    {
      hello[temp]->right = hello[i+1];
    }
  }

  auto y = hello[1];
  preorder(y,K);

  cout<<(count)/2<<endl;

  return 0;


}