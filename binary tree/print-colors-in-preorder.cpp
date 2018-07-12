//Problem Statement -- https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/the-silly-snail-3/

#include <iostream>
#include <unordered_map>

using namespace std;

struct node {
  int data;
  node * left = nullptr;
  node * right = nullptr;
};

struct node * newNode(int key) {
  node * temp = new node;

  temp->data = key;
  temp->left = nullptr;
  temp->right= nullptr;

  return temp;
}

unordered_map<int, node*> m;

void make_tree() {
    int n;
    cin>>n;

    while(n--) {
        int x, y, z;
        cin>>x>>y>>z;

        if(m.find(x) == m.end()) {
            m[x] = newNode(x);
        }
        if(y != 0) {
            m[x]->left = newNode(y);
            m[y] = m[x]->left;
        }
        if(z != 0) {
            m[x]->right = newNode(z);
            m[z] = m[x]->right;
        }
    }
}

void preorder(node* root) {
    if(root == nullptr) 
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        node* root = newNode(1);

        m[1] = root;

        make_tree();
        preorder(root);

        cout<<endl;

        m.clear();
    }
    

    return 0;
}