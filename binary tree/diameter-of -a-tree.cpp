/*
source - https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
*/
#include<iostream>

using namespace std;

struct mytree
{
    int data;
    mytree * left = nullptr;
    mytree * right = nullptr;
};
void insertion(struct mytree * node,int value,string insert)
{
        for(long long i =0;i<insert.size();i++)
        {
            if(insert[i] == 'L')
            {
                if(node->left == nullptr)
                {
                    node->left = new mytree;
                }
                node = node->left;
            }
            else if(insert[i] == 'R')
            {
                if(node->right == nullptr)
                {
                    node->right = new mytree;
                }
                node = node->right;
            }
        }
        node->data = value;
}
int maxDepth(struct mytree* node,int& maxi) 
{
    if (node==NULL) 
        return 0;
    else
    {
             
      int lDepth = maxDepth(node->left,maxi);
      int rDepth = maxDepth(node->right,maxi);

      if((lDepth + rDepth + 1)>maxi)
      {
          maxi = lDepth + rDepth + 1;
      }
      if (lDepth > rDepth) 
        return(lDepth+1);
      else 
        return(rDepth+1);
    }
} 
int main()
{
    int num,val,maxdepth;
    string pos;
    static int maxi;
    
    cin>>num>>val;
    
    mytree * obj = new mytree;
    
    obj->data = val;
    
    for(int i = 0;i<(num-1);i++)
    {
        cin>>pos;
        cin>>val;
        
        insertion(obj,val,pos);
    }
    
    maxdepth = maxDepth(obj,maxi);
    
    cout<<maxi;
    
    
    return 0;
}