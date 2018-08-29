#include<iostream>
#include<queue>
#include<list>

using namespace std;

struct graph{

    bool visited=false;
    list<int> l;
    int value = 0;

};

void assign(graph a[], int u, int value){
    
    a[u].value = value;
}

void add(graph a[], int u, int v){
    a[u].l.push_back(v);
}

 
void DFS(graph a[]    , int node){

    a[node].visited = true;
    cout<<a[node].value<<endl;

    for(auto i: a[node].l){
        if(!a[i].visited){
            DFS(a, i);
        }
    }
}

int main(){

    graph a[4];

    assign(a,0,0);
    assign(a,1,1);
    assign(a,2,2);
    assign(a,3,3);

    add(a,0,1);
    add(a,1,2);
    add(a,1,3);
    add(a,2,3);

    for(int i=0;i<4;i++){
        if(!a[i].visited)
            DFS(a, i);
    }

    return 0;
}

//baap bhai bacha