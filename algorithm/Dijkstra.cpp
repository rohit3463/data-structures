#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

struct node{
    bool visited = false;
    ll dist = LLONG_MAX;
    list<p> l;
};

void addEdge(vector<node> &graph, ll u, ll v, ll w){
    graph.at(u).l.push_back({v,w});
    graph.at(v).l.push_back({u,w});
}

int main(){

    /* Input :

    5 5
    1 2 3
    2 3 2
    2 4 4 
    3 4 1
    4 5 5

    */
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,u,v,w;

    cin>>n>>m;
    vector<node> graph(n+1);

    while(m--){
        cin>>u>>v>>w;
        addEdge(graph, u, v, w);
    }

    priority_queue<p, vector<p>, greater<p> > q;

    graph.at(1).dist = 0;
    q.push({graph.at(1).dist, 1});

    while(!q.empty()){
        auto temp = q.top();
        q.pop();

        graph.at(temp.second).visited = true;

        for(auto &y: graph.at(temp.second).l){

            if(temp.first + y.second < graph.at(y.first).dist){
                graph.at(y.first).dist = temp.first + y.second;
            }

            if(!graph.at(y.first).visited){
                q.push({graph.at(y.first).dist, y.first});
            }
        }
    }

    cout<<"Shortest path of all vertices from source vertex (1) :"<<endl;


    for(auto y=1; y<=n; y++){
        cout<<graph.at(y).dist<<" ";
    }

    cout<<endl;

    return 0;
}