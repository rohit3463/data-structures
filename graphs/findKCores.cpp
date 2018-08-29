#include<iostream>
#include<list>
#include<vector>
#include<climits>


using namespace std;

struct graph
{
	bool visited;
	list < int > l;
};

void addEdge(graph a[], int index, int direct)
{
	a[index].l.push_back(direct);
	a[direct].l.push_back(index);
}

bool DFSUtil(int index,vector < int > & v,graph a[],int k)
{
	a[index].visited = true;

	for(auto & y: a[index].l)
	{
		if(v.at(index) < k)
		{
			v.at(y)--;
		}

		if(!a[y].visited)
		{
			if (DFSUtil(y,v,a,k))
			{
				v.at(index)--;
			}
		}
	}

	return (v.at(index) < k);
}

void findKCores(graph a[],int k,int n)
{
	vector < int > v(n);
	int mindegree = INT_MAX;
	int startvertex = 0;

	for(int i =0;i<n;i++)
	{
		v.at(i) = a[i].l.size();
		if(a[i].l.size() < mindegree)
		{
			mindegree = a[i].l.size();
			startvertex = i;
		}
	}

	if(mindegree < k)
	{
		DFSUtil(startvertex,v,a,k);

		for(int i =0;i<n;i++)
		{
			if(a[i].visited == false)
			{
				DFSUtil(i,v,a,k);
			}
		}

		for(int i =0;i<n;i++)
		{
			if(v.at(i) >= k)
			{
				cout<<'['<<i<<']'<<"->"<<" ";

				for(auto y: a[i].l)
				{
					if(v.at(y) >= k)
					{
						cout<<"->"<<y;
					}
				}
				cout<<endl;
			}

			
		}
	}
}


int main()
{
	int k = 3;
    graph a[9];
    addEdge(a,0, 1);
    addEdge(a,0, 2);
    addEdge(a,1, 2);
    addEdge(a,1, 5);
    addEdge(a,2, 3);
    addEdge(a,2, 4);
    addEdge(a,2, 5);
    addEdge(a,2, 6);
    addEdge(a,3, 4);
    addEdge(a,3, 6);
    addEdge(a,3, 7);
    addEdge(a,4, 6);
    addEdge(a,4, 7);
    addEdge(a,5, 6);
    addEdge(a,5, 8);
    addEdge(a,6, 7);
    addEdge(a,6, 8);
    findKCores(a,k,9);
	return 0;
}