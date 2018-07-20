#include<iostream>
#include<algorithm>

using namespace std;

struct node 
{
    long long data;
    node * left = nullptr;
    node * right = nullptr;
    long long height = 1;
};
node * newNode(long long key)
{
    node * temp = new node;
    temp->data = key;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->height = 1;
    
    return temp;
}
int height(node * temp)
{
    if(temp == nullptr)
    {
        return 0;
    }
    return temp->height;
}

node * insert(node * root,long long key)
{
    if(root == nullptr)
    {
        return newNode(key);
    }
    if(root->data == key)
    {
        node * temp = newNode(key);
        temp->left = root->left;
        root->left = temp;
        
        temp->height = max(height(temp->left),height(temp->right)) + 1;
    }
    if(root->data < key)
    {
        root->left = insert(root->left,key);
    }
    if(root->data > key)
    {
        root->right = insert(root->right,key);
    }
    root->height = max(height(root->left),height(root->right)) + 1;
    
    return root;
}

int main()
{
    long long N,key;
    cin>>N;
    
    node * root = nullptr;
    
    while(N--)
    {
        cin>>key;
        root = insert(root,key);
    }
    cout<<root->height;
    
    return 0;
}