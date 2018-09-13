#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int find_Binomial_coefficient(int n,int k,vector < vector < int > >& arr)
{
	if(k == 0 || n == k)
	{
		return 1;
	}
	if(arr[n][k] != 0)
	{
		return arr[n][k];
	}

	arr[n][k] =  find_Binomial_coefficient(n-1,k-1,arr) + find_Binomial_coefficient(n-1,k,arr);

	return arr[n][k];
}

int main()
{
	int n,k;

	cin>>n>>k;

	vector< vector<int> > arr(n+1, vector<int>(n+1,0));

	cout<<find_Binomial_coefficient(n,k,arr)<<endl;


	return 0;
}