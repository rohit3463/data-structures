/*
Problem statement:-https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/mirrors-and-trees/
*/

#include <iostream>
#include <unordered_map>
#include <utility>
#include <deque>
#include <cstring>

using namespace std;

long long arr[262144];

void get_array(const long long& n) {
    for(long long i = 1 ; i <= n ; ++i) {
        cin>>arr[i];
    }
}

void printTree() {
    long long n;
    cin>>n;

    memset(arr, 0, sizeof arr);
    get_array(n);

    unordered_map<long long, long long> m;
    deque< pair<long long, long long> > q1, q2, left;

    q1.push_back(make_pair(arr[1], 1));

    auto front = q1.front();
    auto back = q1.back();

    while(!q1.empty() || !q2.empty()) {

        if(!q1.empty()) {
            front = q1.front();
            back = q1.back();

            cout<<back.first<<endl;

            m[back.second] = back.second;
            left.push_back(front);
        }

        while(!q1.empty()) {
            front = q1.front();

            q1.pop_front();

            if(arr[2*(front.second)] != 0){
                q2.push_back(make_pair(arr[2*(front.second)], 2*(front.second)));
            }
            if(arr[2*(front.second)+1] != 0){
                q2.push_back(make_pair(arr[2*(front.second)+1], 2*(front.second)+1));
            }
        }

        if(!q2.empty()) {
            front = q2.front();
            back = q2.back();

            cout<<back.first<<endl;

            m[back.second] = back.second;
            left.push_back(front);
        }

        while(!q2.empty()) {
            front = q2.front();

            q2.pop_front();

            if(arr[2*(front.second)] != 0){
                q1.push_back(make_pair(arr[2*(front.second)], 2*(front.second)));
            }
            if(arr[2*(front.second)+1] != 0){
                q1.push_back(make_pair(arr[2*(front.second)+1], 2*(front.second)+1));
            }
        }

    }

    while(!left.empty()) {
        auto front = left.front();

        if(m.find(front.second) == m.end())
        cout<<front.first<<endl;
        
        left.pop_front();
    }
}

int main(){
    long long t;
    cin>>t;

    while(t--) {
        printTree();
        cout<<endl;
    }

    return 0;
}