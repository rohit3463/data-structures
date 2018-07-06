/*
Source -- https://www.geeksforgeeks.org/construct-full-k-ary-tree-preorder-traversal/
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int K = 3;
int arr[] = {1, 2, 3, 4};

struct Node {
    int data;
    vector<Node *> child;

    Node(int c): data(c) {
        child.resize(K, nullptr);
    }
};

int return_level(int size) {
    --size;
    return log10( 1 - (size * (1-K))) / log10 (K);
}

Node* make_tree(int N) {
    static int level = return_level(N);
    static int index = 0;

    if(index < N && level >= 0) {
        Node* t = new Node(arr[index]);

        if(level > 0) {
            index++;
            level--;

            t->child.at(0) = make_tree(N);

            for(int i = 1 ; i < K ; ++i) {
                level--;
                index++;
                t->child.at(i) = make_tree(N);
            }
        }

        level++;
        return t;
    }

    return nullptr;
}

void postorder(Node* root) {
    if(root == nullptr)
        return;
    
    for(auto& i : root->child) {
        postorder(i);
    }
    cout<<root->data<<" ";
}

int main() {
    Node* root = make_tree(4);
    postorder(root);

    cout<<endl;

    return 0;
}