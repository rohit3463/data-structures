#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> Interval;

struct node {
    Interval interval;
    node* left;
    node* right;
    int max;
};

node* newNode(Interval interval) {
    node* temp = new node;
    temp->interval = interval;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->max = interval.second;
}

int get_max(node* root) {
    if(root == nullptr)
        return 0;
    return root->max;
}

void insert(node*& root, Interval i) {
  if(root == nullptr) {
    root = newNode(i);
    return;
  }
  if(root->interval.first > i.first)
        insert(root->left, i);
    else
        insert(root->right, i);
    
    int m = max(get_max(root->left), get_max(root->right));

    if(root->max <  m)
        root->max =  m;
}

bool isOverlap(Interval root, Interval b) {
    if( (b.first > root.first && b.first < root.second) || (b.second > root.first && b.second < root.second) 
        || (root.first > b.first && root.first < b.second) || (root.second > b.first && root.second < b.second) )
            return true;
    
    return false;
}

bool check_overlap(node* root, Interval i) {
    if(root == nullptr)
        return false;
    
    if(isOverlap(root->interval, i))
        {
            cout<<'['<<i.first<<','<<i.second<<']'<<" ";
            cout<<"conflicts with ";
            cout<<'['<<root->interval.first<<','<<root->interval.second<<']'<<endl;
            return true;
        }
    
    if(i.first < root->interval.first)
        return check_overlap(root->left, i);
    else    
        return check_overlap(root->right, i);
}

bool wrapper(node *& root,Interval i)
{
    bool result = check_overlap(root,i);

    insert(root,i);

    return result;
}

void inorder(node* root) {
    if(root){
        inorder(root->left);
        cout<<"{"<<root->interval.first<<" "<<root->interval.second<<"} ";
        inorder(root->right);
    }
}

int main() {
    node* root = nullptr;
    wrapper(root, make_pair(1,5));
    wrapper(root, make_pair(3,7));
    wrapper(root, make_pair(2,6));
    wrapper(root, make_pair(10,15));
    wrapper(root, make_pair(5,6));
    wrapper(root, make_pair(4,100));

    return 0;
}