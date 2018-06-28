#include<iostream>
#include<queue>
#include<stack>

using namespace std;
class mytree
{
private:
    mytree * left_node;
    int data;
    mytree * right_node;
public:
    mytree(int value)
    {
        this->data = value;
        this->left_node = nullptr;
        this->right_node = nullptr;
    }
    void levelordertraverse()
    {
        queue < mytree * > temp;
        mytree * it = this ;

        while(it != nullptr)
        {
            cout<<it->data<<" ";
            if(it->left_node != nullptr)
            temp.push(it->left_node);
            if(it->right_node != nullptr)
            temp.push(it->right_node);
            if(temp.empty())
            {
                return;
            }
            it = temp.front();
            temp.pop();
        }
    }
    void insert_node(int taken)
    {
        queue < mytree * > temp;
        mytree * it = this ;

        while(it != nullptr)
        {
            if(it->left_node == nullptr)
            {
                it->left_node = new mytree(taken);
                return;
            }
            else if (it->right_node == nullptr)
            {
                it->right_node = new mytree(taken);
                return;
            }
            else
            {
                if(it->left_node != nullptr)
                temp.push(it->left_node);
                if(it->right_node != nullptr)
                temp.push(it->right_node);

                it = temp.front();
                temp.pop();
            }
        }
    }
   

    mytree *& left()
    {
        return this->left_node;
    }
    mytree *& right()
    {
        return this->right_node;
    }
    void print()
    {
        cout<<this->data<<" ";
    }
friend bool foldable(mytree *);
friend bool foldable_child(mytree *,mytree *);
};

 bool foldable(mytree * current)
    {

        if(current == nullptr)
        {
            return true;
        }
       return foldable_child(current->left_node,current->right_node);
    }
bool foldable_child(mytree * n1,mytree * n2)
    {
        if(n1 == nullptr && n2 == nullptr)
            return true;
        if(n1 == nullptr || n2 == nullptr)
            return false;
        else
            return foldable_child(n1->left_node,n2->right_node) && foldable_child(n1->right_node,n2->left_node);
    }
int main()
{
    mytree * obj = new mytree(1);

    obj->insert_node(2);
    obj->insert_node(3);
    obj->insert_node(4);
    obj->insert_node(5);
    obj->insert_node(6);
    obj->insert_node(7);

    if(foldable(obj))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }


    return 0;
}