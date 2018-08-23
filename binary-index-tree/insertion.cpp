#include<iostream>
#include<vector>

using namespace std;

int getSum(vector < int >& BIT,int index)
{
	index = index - 1;

	int sum = 0;

	while(index > 0 )
	{
		sum += BIT[index];

		index -= index & (-index);
	}

	return sum;
}

void updateBIT(vector < int >& BIT,int n,int index,int val)
{
	index = index + 1;

	while(index <= n)
	{
		BIT[index] += val;

		index += index & (-index);
	}
}

vector < int > makeBIT(vector < int > arr,int n)
{
	vector < int > BIT(n+1,0);

	for(int i=0;i<n;i++)
	{
		updateBIT(BIT,n,i,arr[i]);
	}

	return BIT;
}


int main()
{
	vector < int > arr {2,1,1,3,2,3,4,5,6,7,8,9};

	vector < int > BIT = makeBIT(arr,arr.size());

	int l ,r;

	cout<<"enter the range of array :-"<<" =";
	cin>>l>>r;

	cout<<(getSum(BIT,r)-getSum(BIT,l))<<endl;
	return 0;
}