#include<iostream>
#include<unordered_map>
#include<set>
#include<iterator>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n,q,no,tatti,max=0;
    
    set<long long> s;
    unordered_map<long long, long long> m;
    
    cin>>n;
    cout<<n;
    for(long long i=0;i<n;i++){
        cin>>no;
        if(no>max)
            max= no;
        s.insert(no);
        m[no]++;
    }
    
    cin>>q;
    cout<<q;
    while(q--){
        
        cin>>tatti;
        if(tatti<max){
            s.insert(tatti);
            m[tatti]++;
        }
    }
    
    auto it= s.begin();
    while(it != s.end()){
        cout<< (*it) <<" ";
        m[*it]--;
        
        ++it;
    }
    
    auto temp = s.rbegin();
    while(temp != s.rend()){
        if(m[*temp]){
            cout<< (*temp) <<" ";
            m[*temp]--;
        }
        
        ++temp;
    }
    
    return 0;
}