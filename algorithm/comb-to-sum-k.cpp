#include<iostream>
#include<vector>

using namespace std;



void initialize(int n,vector < int >& dp)
{
	for(int i=0;i<n;i++)
	{
		dp.push_back(-1);
	}
}

int solve(int n,vector< int >& arr,vector < int >& dp)
{
	if(n < 0)
	{
		return 0;
	}
	else if(n == 0)
	{
		return 1;
	}
	else if(dp[n] != -1)
	{
		return dp[n];
	}

	dp[n] = 0;

	for(auto& y: arr)
	{
		dp[n] += solve(n-y,arr,dp);
	}

	return dp[n];
}

int main()
{
	vector < int > dp;
	int N;
	cin>>N;

	int n;

	cin>>n;

	initialize(100,dp);


	vector < int > arr(N);

	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}

	cout<<solve(n,arr,dp)<<endl;


	return 0;
}