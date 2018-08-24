#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int getSum(vector < int >& BIT,int index)
{
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

	while(index <= n)
	{
		BIT[index] += val;

		index += index & (-index);
	}
}

int makeBIT(vector < int > arr,int n)
{
	int max_element = INT_MIN,result=0;

	for(auto& y:arr)
	{
		if(y>max_element)
		{
			max_element = y;
		}
	}
	vector < int > BIT(max_element + 1,0);

	for(int i=n-1;i>=0;i--)
	{
		result += getSum(BIT,arr[i]-1);
		updateBIT(BIT,n,arr[i],1);
	}

	return result;
}


int main()
{
	vector < int > arr {5,4,3,2,1};

	int result = makeBIT(arr,arr.size());

	cout<<result<<endl;
	return 0;
}