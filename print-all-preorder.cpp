#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

void print_all_preorder(vector < int >& arr,int size)
{
	vector < int > dup(arr);

	set < vector < int> > hello;

	do
	{
		hello.insert(dup);
		
	}
	while(next_permutation(dup.begin() + 1,dup.begin() + size));

	for(int i=1;i<(size-1);i++)
	{
		dup = arr;
		sort(dup.begin(),dup.begin() + i -1);
		sort(dup.begin() + i + 1,dup.begin() + size-1);

		do
		{
			//cout<<i<<endl;
			swap(*(dup.begin()),*(dup.begin() + i));
			hello.insert(dup);
			swap(*(dup.begin()),*(dup.begin() + i));
		}
		while(next_permutation(dup.begin(),dup.begin() + i ) || next_permutation(dup.begin() + i + 1,dup.begin() + size));
	}
	dup = arr;
	do
	{
		swap(*(dup.begin()),*(dup.begin() + size-1));
		hello.insert(dup);
		swap(*(dup.begin()),*(dup.begin() + size-1));
		//cout<<size<<endl;
	}
	while(next_permutation(dup.begin() , dup.end() - 1));

	for(auto& y : hello)
	{
		for(auto& x : y)
		{
			cout<<x<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	vector < int > arr;
	int temp;

	for(int i =0;i<4;i++)
	{
		cin>>temp;

		arr.push_back(temp);
	}
	print_all_preorder(arr,arr.size());

	return 0;
}