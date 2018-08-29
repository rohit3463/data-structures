#include<iostream>
#include<list>
#include<vector>

using namespace std;

struct graph
{
	bool visited = false;
	list < int > l;
};

void addEdge(vector < graph >& a, int index, int direct)
{
	a[index].l.push_back(direct);
}

void DFS(vector <graph>& v, int node,int &count){

    v[node].visited = true;
 

    for(auto y: v[node].l)
    {
        if(!v[y].visited)
        {
            DFS(v, y, count);
        }
    }

    count++;
}

void findMother(vector < graph >& g,int n)
{
	int count = 0;
	vector < graph > r;
	for(int i =0;i<n;i++)
	{
		count =0;
		r = g;
		DFS(r,i,count);

		if(count >= n)
		{
			cout<<i<<endl;
		}
	}
}

int main()
{
	vector < graph > g(7);

	addEdge(g,0, 1);
    addEdge(g,0, 2);
    addEdge(g,1, 3);
    addEdge(g,4, 1);
    addEdge(g,6, 4);
    addEdge(g,5, 6);
    addEdge(g,5, 2);
    addEdge(g,6, 0);

    findMother(g, 7);
 
	return 0;
}
