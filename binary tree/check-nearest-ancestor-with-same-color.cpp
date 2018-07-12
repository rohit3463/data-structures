/*
problem-statement :- https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/mancunian-and-colored-tree/
*/

#include<iostream>
#include<list>
#include<unordered_map> 
#include<climits>

using namespace std;

int main()
{
    unordered_map< long long ,list < long long > > hello;
    long long N,C,temp,req,found;
    cin>>N>>C;
    long long colors[N+1];
    
    hello[1].push_back(INT_MIN);
    for(long long i=1;i<N;i++)
    {
        cin>>temp;
        if(hello.find(temp) != hello.end())
        {
            hello[i+1] = hello[temp];
        }
        hello[i+1].push_front(temp);
    }
    for(long long i=0;i<N;i++)
    {
        cin>>colors[i];
    }
    for(int i=0;i<N;i++)
    {
        req = colors[i];
        for(auto& y : hello[i+1])
        {
            if(y != INT_MIN)
            {
                if(colors[y-1] == req)
                {
                    found = colors[y-1];
                    cout<<y<<" ";
                    break;
                }
            }
        }
        if(found != req)
        {
            cout<<"-1"<<" ";
        }
        found = 0;
    }
    return 0;
}