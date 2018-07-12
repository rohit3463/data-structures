/*
Problem statement:-https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/gandhi-tree-march/
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include <algorithm>

using namespace std;

unordered_map < int , vector < char > > hello;

void store_map(string& str,int level, int& index)
{

  if(str[index] == '.')
  {
    index++;
    return;
  }

  hello[level].push_back(str[index]);

  index++;

  if(str[index] == '(')
  {
    index++;

    store_map(str,level-1,index);
  }

  store_map(str,level+1,index);

  if(str[index] == ')')
  {
    index++;
    return;
  }


}

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int n, index = 0;
        cin>>n;
        
        string s;
        cin>>s;
        
        store_map(s, 0, index);
        
        if(hello.find(n) != hello.end()) {
            sort(hello[n].begin(), hello[n].end());

            for(const char& i : hello[n])
                cout<<i;
            
            cout<<endl;
        }
        else {
            cout<<"Common Gandhijee!\n";
        }

        hello.clear();

    }
    return 0;
}