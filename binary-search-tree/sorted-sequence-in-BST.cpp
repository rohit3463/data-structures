#include<iostream>
#include<list>

using namespace std;

struct node
{
    int data;
    node * left = nullptr;
    node * right = nullptr;
};

struct node * newNode(int key)
{
    node * temp = new node;
    temp->data = key;
    temp->left = nullptr;
    temp->right = nullptr;

    return temp;
}

void inorder(node *root, list<int>& q){

    if(root == nullptr)
        return ;

    inorder(root->left, q);
    if(root->data == q.front())
        q.pop_front();
    inorder(root->right, q);
}

void wrapper(node* root, list<int>& q){

    inorder(root, q);

    if(!q.empty())
        cout<<"NO"<<endl;

    else cout<<"YES"<<endl;
}

node * insert(node * root,int key)
{
  if(root == nullptr)
  {
    return newNode(key);
  }

  if(key < root->data)
  {
    root->left = insert(root->left,key);
  }
  else if(key > root->data)
  {
    root->right = insert(root->right,key);
  }

  return root;
}

int main(){

    struct node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);

    list<int> q{4, 6, 8, 14};

    wrapper(root, q);

     return 0;

}