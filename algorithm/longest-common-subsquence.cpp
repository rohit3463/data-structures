#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int LCS(string& a,string& b)
{
	int L[a.length()+1][b.length()+1];

	for(int i =0;i<a.length()+1;i++)
	{
		L[i][0] = 0;
	}
	for(int i=0;i<b.length()+1;i++)
	{
		L[0][i] = 0;
	}

	for(int i = 1 ;i<a.length()+1;i++)
	{
		for(int j=1;j<b.length()+1;j++)
		{
			if(a[i] == b[j])
			{
				L[i][j] = L[i-1][j-1]+1;
			}
			else
			{
				L[i][j] = max(L[i-1][j],L[i][j-1]);
			}
		}
	}

	return L[a.length()][b.length()];
}

int main()
{
	string a = "AGGTAB";
	string b = "GXTXAYB";

	cout<<LCS(a,b)<<endl;
	return 0;
}