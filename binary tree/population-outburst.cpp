#include<iostream>
#include<queue>
#include<unordered_map>
#include<utility>

using namespace std;
 
int main()
{
    long long N,kid,parent=0,j=1;
    cin>>N;
    cin>>kid;
    
    queue<pair<long long,long long>>hello;
    unordered_map < long long,long long> level;
    
    while(kid--)
    {
        hello.push(make_pair(parent,j));
        j++;
    }
    level[0] = 0;
    
    for(long long i=0;i<N;i++)
    {
        j=1;
        cin>>parent;
        cin>>kid;
        level[parent] = level[hello.front().first] + 1;
        cout<<hello.front().first<<level[parent]<<hello.front().second<<endl;
        
        hello.pop();
        
        while(kid--)
        {
            hello.push(make_pair(parent,j));
            j++;
        }
    }
    
    return 0;
}