#include<iostream>
#include<list>
#include<vector>
#include<stack>

using namespace std;

struct graph
{
	bool visited = false;
	list < int > l;
	int value;

};
void assign(graph a[],int index, int value)
{
	a[index].value = value;
}

void addEdge(graph a[], int index, int direct)
{
	a[index].l.push_back(direct);
}

void DFS(graph v[], int node, stack<int> &s){

    v[node].visited = true;

    for(auto y: v[node].l)
        if(!v[y].visited)
            DFS(v, y, s);

    s.push(v[node].value);
}
vector < graph > transpose(graph a[],int n)
{
	vector < graph > hello(n);

	for(int i =0;i<n;i++)
	{
		hello[i].value = a[i].value;
		for(auto y: a[i].l)
		{
			hello[y].l.push_back(i);
		}
	}

	return hello;
}
void printSCC(vector<graph> &v, int node){

    if(v[node].visited == false)
    {
    	cout<<node<<" ";
    }
    v[node].visited = true;

    for(auto y: v[node].l){
        if(!v[y].visited)
            printSCC(v, y);
    }
}

void SCC(graph a[],int n)
{
	stack < int > s;

	DFS(a,0,s);

	vector < graph > hello = transpose(a,n);


	while(!s.empty())
	{
		int temp = s.top();
        s.pop();

        if(!hello[temp].visited){

            printSCC(hello, temp);
            cout<<endl;
        }
	}


}

int main()
{
	graph v[5];

	assign(v,0,0);
    assign(v,1,1);
    assign(v,2,2);
    assign(v,3,3);
    assign(v,4,4);

    addEdge(v, 1, 0);
    addEdge(v, 0, 2);
    addEdge(v, 2, 1);
    addEdge(v, 0, 3);
    addEdge(v, 3, 4);

    SCC(v,sizeof(v)/sizeof(v[0]));



	return 0;
}