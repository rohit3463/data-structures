#include<iostream>
#include<unordered_map>

using namespace std;

bool check_anscestor(unordered_map < int, int >& checker,int anscestor,int child)
{
	while(checker.find(child) != checker.end())
	{
		if(checker[child] == anscestor)
		{
			return true;
		}
		child = checker[child];
	}
	return false;
}

int main()
{
	unordered_map< int, int > checker;
	int edges[][2] = {
        { 0, 1 },
        { 0, 2 },
        { 1, 3 },
        { 1, 4 },
        { 2, 5 },
        { 4, 6 },
        { 5, 7 }
    };

    for(int i=0;i<sizeof(edges)/(2*sizeof(int));i++)
    {
    	checker[edges[i][1]] = edges[i][0];
    }

    int anscestor = 4,child = 3;

    if(check_anscestor(checker,anscestor,child))
    {
    	cout<<"YES"<<endl;
    }
    else
    {
    	cout<<"NO"<<endl;
    }

    return 0;
}