#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
#include<string>

using namespace std;

struct graph
{
	bool visited = false;
	list < int > l;
	int value = 0;
	int count =0;
};

unordered_map < int , int > m;

int comp(int a, int b)
{
	string first = to_string(a);
	string second = to_string(b);

	int count =0;

	for(int i=0;i<first.length();i++)
	{

		if(first[i] != second[i])
		{
			count++;
		}
	}

	return count;
}

void printPrimes(int n,vector < graph >& v)
{
	vector < bool > visited(n,false);
	for(int p = 2;p*p <= n;p++)
	{
		if(visited.at(p) == false)
		{

			for(int i=2*p;i<n;i += p)
			{
				visited.at(i) = true;
			}
		}
	}

	for(int i=1000;i<n;i++)
	{
		if(visited.at(i) == false)
		{
			graph g;
			g.value = i;
			int x=0;
			v.push_back(g);
			
			for(int j = 0;j<v.size()-1;j++)
			{
				if(comp(v.at(j).value,g.value) == 1)
				{
					x = 1;
					v.at(j).l.push_back(v.size()-1);
					v.at(v.size()-1).l.push_back(j);
				}
			}
			m[g.value] = v.size()-1;
		}
	}
}

int BFS(vector<graph> &g, int index1, int index2){
	index1 = m[index1];
	index2 = m[index2];
    queue<int> q;
    g[index1].visited = true;
    g[index1].count = 1;
    q.push(index1);

    while(!q.empty()){

        int temp = q.front();
        q.pop();

        for(auto y: g[temp].l){
            if(!g[y].count){
                g[y].count = g[temp].count + 1;
                q.push(y);
                
            }
            if(y == index2)
                return g[y].count-1;

            
        }
    }
}

// int BFS(int start,int finish,vector < graph >& g)
// {
// 	int start_index = m[start];
// 	int finish_index = m[finish];

// 	queue < int > q;

// 	int count =0;

// 	q.push(start_index);

// 	g[start_index].visited  = true;

// 	while(q.front() != finish_index)
// 	{
// 		int it = q.front();

// 		q.pop();

// 		count++;

// 		for(auto y : g[it].l)
// 		{
// 			if(!g[y].visited)
// 			{
// 				q.push(y);

// 				g[y].visited = true;
// 			}
// 		}
// 	}

// 	return count;
// }

int main()
{
	int start,finish;

	cin>>start>>finish;

	vector < graph > g;

	printPrimes(9999,g);

	int count = BFS(g,start,finish);

	cout<<count<<endl;

	return 0;
}



