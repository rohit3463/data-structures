// Problem Statement -- https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* left = nullptr;
    node* right = nullptr;
};

node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    return temp;
}

void f(node*& root, int& index, int& succ, vector<int>& v) {
    if(root == nullptr) {
        root = newNode(v.at(index));
        --index;
        return;
    }
    if(v.at(index) < root->data) {
        succ = root->data;
        f(root->left, index, succ, v);
    }
    else {
        f(root->right, index, succ, v);
    }
}

int main() {
    vector<int> v{8, 58, 71, 18, 31, 32, 63, 92, 
         43, 3, 91, 93, 25, 80, 28};
    
    int index = v.size() - 1, succ = -1;
    node* root = nullptr;

    for(int i = index ; i >= 0 ; --i) {
        succ = -1;
        f(root, index, succ, v);
        cout<<succ<<" ";
    }
    cout<<endl;

    return 0;
}