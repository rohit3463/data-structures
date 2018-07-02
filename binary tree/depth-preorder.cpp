/*
source - https://www.geeksforgeeks.org/calculate-depth-full-binary-tree-preorder/
*/
#include<iostream>
#include<algorithm>

using namespace std;

int depth_preorder(string& str)
{
	static int index = 0;

	if(index >= str.size() || str[index] == 'l')
	{
		return 0;
	}

	index++;

	int left = depth_preorder(str);

	index++;

	int right = depth_preorder(str);

	return max(left,right) + 1;
}

int main()
{
	string str = "nlnnlll";

	int depth = depth_preorder(str);

	cout<<depth<<endl;
}