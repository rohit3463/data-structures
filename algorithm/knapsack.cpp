#include<iostream>
#include<algorithm>

using namespace std;

int knapsack(int n,int W,int w[],int val[])
{
	if(w[n-1] == 0 || W == 0)
	{
		return 0;
	}
	if(w[n-1] > W)
	{
		knapsack(n-1,W,w,val);
	}

	return max(val[n-1] + knapsack(n-1,W - w[n-1],w,val),knapsack(n-1,W,w,val));
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