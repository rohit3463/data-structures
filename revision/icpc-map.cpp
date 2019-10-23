#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct ct
{
    long long my_count = 0;
    long long x_1 = 0;
    long long x_0 = 0;
};

int main() {
    
    long long n,T;
    
    cin>>T;
    
    while(T--)
    {
        unordered_map <string, ct> hello;
        long long total = 0;
        cin>>n;
        string st;
        long long digit;
        for(int i=0;i<n;i++)
        {
            cin>>st;
            cin>>digit;
            
            if(digit == 0)
            {
                hello[st].x_0 += 1;
                total -= hello[st].my_count;
                if(hello[st].x_0 > hello[st].x_1)
                {
                    hello[st].my_count = hello[st].x_0;
                }
                total += hello[st].my_count;
            }
            else
            {
                hello[st].x_1 += 1;
                total -= hello[st].my_count;
                if(hello[st].x_1 > hello[st].x_0)
                {
                    hello[st].my_count = hello[st].x_1;
                }
                total += hello[st].my_count;
            }
        }

        cout<<total<<endl;
    }
    return 0;
    
}
