#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

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
	
	 vector<int> v {0,8,6,7,2,4,5,3};

	 v.push_back(5);
	 
	 int N = v.size()-1;
	 int i = N;

	 while((i/2)>0){
	 	
	 	if(v.at(i) > v.at(i/2)){
	 		swap(v.at(i), v.at(i/2));
	 		i/=2;
	 	}
	 	
	 	else break;

	 }

	for(int i=1;i<v.size();i++)
		cout<<v[i]<<" ";
	
	cout<<endl;

	return 0;
}