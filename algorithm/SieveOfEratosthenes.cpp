#include<iostream>
#include<vector>

using namespace std;

void printPrimes(int n)
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

	for(int i=2;i<n;i++)
	{
		if(visited.at(i) == false)
		{
			cout<<i<<" ";
		}
	}
}

int main()
{
	int n;
	cin>>n;

	printPrimes(n);
	return 0;
}