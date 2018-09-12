#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin>>N;

	vector < int > arr(N);

	for(int i =0;i<N;i++)
	{
		cin>>arr[i];
	}

	for(int i =1;i<N;i++)
	{
		int j = i;
		while((arr[j-1] < arr[j])&&j>0)
		{
			int temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;

			j--;
		}
	}

	cout<<endl;

	for(auto& y: arr)
	{
		cout<<y<<" ";
	}
	cout<<endl;

	return 0;
}