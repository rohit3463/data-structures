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
  temp->right= nullptr;

  return temp;
}

bool leaf_traversal(node *root1, node *root2){

    if(root1 == nullptr && root2 == nullptr)
        return false;

    queue<node* > q, q2, q3;

    q.push(root1);

    node *temp1 = nullptr;

    while(!q.empty()){

        temp1 = q.front();
        q.pop();

        if(temp1->left == nullptr && temp1->right == nullptr){
            q2.push(temp1);
        }

        else{
            if(temp1->left != nullptr)
                q.push(temp1->left);

            if(temp1->right != nullptr)
                q.push(temp1->right);
        }
    }

    q.push(root2);

    node *temp2 = nullptr;

    while(!q .empty()){

        temp2 = q.front();
        q.pop();

        if(temp2->left == nullptr && temp2->right == nullptr){
            q3.push(temp2);
        }

        else{
            if(temp2->left != nullptr)
                q.push(temp2->left);

            if(temp2->right != nullptr)
                q.push(temp2->right);
        }
    }

    while(!q2.empty() || !q3.empty()){

        if(q2.front()== nullptr && q3.front() != nullptr)
            return false;

        else if(q2.front()!= nullptr && q3.front() == nullptr)
            return false;

        else if(q2.front() != nullptr && q3.front() != nullptr)
            if(q2.front()->data != q3.front()->data)
                return false;

        q2.pop();
        q3.pop();


    }

    return true;
}

int main(){

    node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);
 
    node *root2 = newNode(0);
    root2->left = newNode(1);
    root2->right = newNode(5);
    root2->left->right = newNode(4);
    root2->right->left = newNode(6);
    root2->right->right = newNode(7);

    if(leaf_traversal(root1, root2))
        cout<<"YES"<<endl;

    else cout<<"NO"<<endl;

    return 0;

}