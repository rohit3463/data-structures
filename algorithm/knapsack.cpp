#include<iostream>
#include<algorithm>

using namespace std;

int knapsack(int n,int W,int w[],int val[])
{
	int k[n+1][W+1];

	for(int i=0;i<=n;i++)
	{
		for(int j = 0;j<=W;j++)
		{
			if(i==0 || j==0)
			{
				k[i][j] = 0;
			}
			else if(w[i-1] <= j)
			{
				k[i][j] = max(val[i-1] + k[i-1][j- w[i-1]],k[i-1][j]);
			}
			else
			{
				k[i][j] = k[i-1][j];
			}
		}
	}

	return k[n][W];
}

int main()
{
	int w[3] = {10,20,30};
	int val[3] = {60,100,120};

	int W = 50;

	int n = sizeof(w)/sizeof(w[0]);

	cout<<knapsack(n,W,w,val)<<endl;
	return 0;
}