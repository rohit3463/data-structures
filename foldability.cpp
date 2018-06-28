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
};

 bool foldable(mytree * current)
    {

        if(current == nullptr)
        {
            return true;
        }
        else if(current->right_node != nullptr && current->left_node != nullptr)
        {
            return !(foldable(current->left_node->left_node) ^ foldable(current->right_node->right_node)) && !(foldable(current->left_node->right_node) ^ foldable(current->right_node->left_node));
        }
        else 
        {
            return false;
        }
    }
int main()
{
    mytree * obj = new mytree(1);

    obj->insert_node(2);
    obj->insert_node(3);
    obj->insert_node(4);
    obj->insert_node(5);
    obj->insert_node(6);

    obj->levelordertraverse();

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