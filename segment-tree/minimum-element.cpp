#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

void maketree(int tree[],int start,int end,int index,int arr[])
{
	if(start == end)
	{
		tree[index] = arr[start];
		return;
	}
	int mid = (start +  end)/2;

	maketree(tree,start,mid,2*index+1,arr);

	maketree(tree,mid+1,end,2*index+2,arr);

	tree[index] = min(tree[2*index+1],tree[2*index+2]);

	return;
}

int getMIN(int tree[],int start,int end,int index,int l,int r)
{
	if(l <= start && r >= end)
	{
		return tree[index];
	}
	if(r<start || l>end)
	{
		return INT_MAX;
	}
	if(start != end)
	{
		int mid = (start +  end)/2;

		return min(getMIN(tree,start,mid,2*index+1,l,r),getMIN(tree,mid+1,end,2*index+2,l,r));
	}
}


int main()
{
	int arr[10] = {3,4,6,1,4,7,9,0,4,2};

	int tree[(1<<(9))-1];

	maketree(tree,0,9,0,arr);

	cout<<getMIN(tree,0,9,0,5,6);

	return 0;
}