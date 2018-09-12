#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int matrixchain(vector<int>& arr,int n)
{
	int m[n][n];

	for(int i =1;i<n;i++)
	{
		m[i][i] = 0;
	}
	int q;

	for(int L = 2;L<n;L++)
	{
		for(int i = 1;i<(n-L+1);i++)
		{
			int j = L + i - 1 ;

			m[i][j] = INT_MAX;

			for(int k=i;k<=j;k++)
			{
				q = m[i][k] + m[k+1][j] + arr[i-1] * arr[k] * arr[j];

				if(q < m[i][j])
				{
					m[i][j] = q;
				}
			}
		}
	}

	return m[1][n-1];
}

int main()
{
	vector < int > arr{1,2,3,4,5};

	cout<<matrixchain(arr,5)<<endl;

	return 0;
}