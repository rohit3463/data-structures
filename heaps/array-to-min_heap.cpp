#include<iostream>

using namespace std;

void max_heap(int arr[], int i, int N){
	
	int left = 2*i+1;
	int right = 2*i +2;
	int smallest;

	if(left<= N && arr[left] < arr[i]){
		smallest = left;
	}
	else  smallest =i;
	if(right<= N && arr[right] < arr[smallest]){
		smallest = right;
	}

	if(smallest != i){
		swap(arr[i], arr[smallest]);
		max_heap(arr, smallest, N);
	}
}

int main(){
	
	int arr[] = {4, 5, 1, 6, 7, 3, 2};

	int N = sizeof(arr)/sizeof(arr[0]);
	N--;
	for(int i=(N/2); i>=0; i--){
		max_heap(arr, i, N);
	}

	for(int i=0;i<=N;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	return 0;
}