#include<iostream>
#include<vector>

using namespace std;

int partition(vector < int >& arr, int low, int high)
{
	int pivot = arr[high];

	int i = low -1;

	for(int j=low;j<=high-1;j++)
	{
		if(arr[j] <= pivot)
		{
			i++;

			int temp = arr[i];

			arr[j] = arr[i];

			arr[i] = temp;
		}

	}

	int temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;

	return i+1;
}

void quicksort(vector < int >& arr, int low , int high)
{
	if(low < high)
	{
		int p = partition(arr,low,high);

		quicksort(arr,p+1,high);
		quicksort(arr,low,p-1);
	}
}

int main()
{
	int N;
	cin>>N;

	vector < int > arr(N);

	for(int i =0;i<N;i++)
	{
		cin>>arr[i];
	}

	quicksort(arr,0,N-1);

	cout<<endl;

	for(auto& y: arr)
	{
		cout<<y<<" ";
	}
	cout<<endl;


	return 0;

}