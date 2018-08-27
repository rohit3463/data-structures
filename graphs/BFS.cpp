#include<iostream>
#include<queue>
#include<list>

using namespace std;

struct graph
{
	bool visited = false;
	list < int > l;
	int value = 0;
};

void assign(graph a[],int index, int value)
{
	a[index].value = value;
}

void add(graph a[], int index, int direct)
{
	a[index].l.push_back(direct);
}

void BFS(graph a[])
{
	queue < int > q;

	q.push(0);

	a[0].visited = true;

	while(!q.empty())
	{
		int t = q.front();

		q.pop();

		cout<<a[t].value<<" ";

		for(auto y : a[t].l)
		{
			if(!a[y].visited)
			{
				q.push(y);

				a[y].visited = true;
			}
		}
	}

	cout<<endl;
}

int main()
{

	graph a[4];

	assign(a,0,50);
	assign(a,1,60);
	assign(a,2,70);
	assign(a,3,20);

	add(a,0,1);
	add(a,1,2);
	add(a,1,3);
	add(a,2,3);

	BFS(a);

	return 0;
}