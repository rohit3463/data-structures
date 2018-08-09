#include<iostream>
#include<vector>

using namespace std;

void max_heap(vector<int> &arr, int i, int N){
	
	int left = 2*i;
	int right = 2*i +1;
	int largest;

	if(left<= N && arr[left] >= arr[i]){
		largest = left;
	}
	else  largest =i;
	if(right<= N && arr[right] >= arr[largest]){
		largest = right;
	}

	if(largest != i){
		swap(arr[i], arr[largest]);
		max_heap(arr, largest, N);
	}
}

int main(){
	
	vector<int> v {0,9,8,6,7,4,5,3,2};

	swap(*(v.begin()+1), *(v.end()-1));

	v.pop_back();

	max_heap(v,1,v.size()-1);

	for(int i=1;i<v.size();i++)
		cout<<v[i]<<" ";

	cout<<endl;

	return 0;


}