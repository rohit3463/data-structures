#include<iostream>
#include<queue>
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

void reverseTreePath(node* root,queue<int>&q,int key){
    bool static flag = false;

    

    if(root == nullptr)
    return;

    if(flag == false){

    if(root->data < key){
        q.push(root->data);
        reverseTreePath(root->right,q,key);
    }

    if(root->data > key){
        q.push(root->data);
        reverseTreePath(root->left,q,key);
    }
  
    if(root->data == key){
     
        q.push(root->data);
        flag = true;
    }
}

    if(flag == true){
      root->data = q.front();
      q.pop();
    }

    return;
}





void inorder(node * root)
{
  if(root == nullptr)
  {
    return;
  }

  inorder(root->left);

  cout<<root->data<<" ";

  inorder(root->right);
}

struct node* insert(struct node* node,
                              int key)
{
    
    if (node == nullptr)
        return newNode(key);
 
   
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
   
    return node;
}
int main()
{
    struct node* root = nullptr;
    queue<int> q1;

    int k = 80;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
   
    reverseTreePath(root,q1,k);
 

    inorder(root);
    return 0;
}