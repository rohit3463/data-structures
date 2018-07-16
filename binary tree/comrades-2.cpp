/*
Problem statement - https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/comrades-ii-6/
*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>

using namespace std;

long long int sum_array[100000];

void hand_shakes(unordered_map<long long int, vector<long long int> >& m, long long int value, long long int prev, long long int& sum){
    
    sum += prev;
    sum_array[value] = prev;

    if(m.find(value) == m.end())
        return;
    
    for(auto i : m[value]){
        hand_shakes(m, i, prev+1, sum);
    }
    

    
}

unordered_map<long long int, vector<long long int> > make_map(long long int N, long long int& index){
    long long int n;
    unordered_map<long long int, vector<long long int> >m;
    for(long long int i=1; i<=N ;i++){
            cin>> n;
            if(n == 0){
                index = i;
                continue;
            }
            m[n].push_back(i);
        }
        
    return m;
}
int main(){
    long long int T,N, index =0;
    cin>>T;
    while(T--){
        
        cin>>N;
        long long int sum = 0;
        memset(sum_array , 0 , 100000);
        unordered_map<long long int, vector<long long int> > m = make_map(N, index);
        hand_shakes(m, index, 0, sum);
        long long fist_bumps =( N*(N-1) - (2*sum))/2;
        cout<<sum<<" "<<fist_bumps<<endl;
        
    
    }
}