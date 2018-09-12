#include<iostream>
#include<list>
#include<vector>

using namespace std;

void intialize(vector<int>& A,vector< int >& s)
{
	for(int i=0;i<A.size();i++)
	{
		A.at(i) = i;
		s.at(i) = 1;
	}
}

int root(vector<int>& A,int i)
{
	while(A.at(i) != i)
	{
		A.at(i) = A.at(A.at(i));
		i = A.at(i);
	}

	return i;
}

void weighted_union(vector<int>& A,vector<int>& s,int a,int b)
{
	int root_a = root(A,a);
	int root_b = root(A,b);

	if(s.at(root_a) <= s.at(root_b))
	{
		A.at(root_a) = A.at(root_b);
		s.at(root_b) += s.at(root_a); 
	}
	else
	{
		A.at(root_b) = A.at(root_a);
		s.at(root_a) += s.at(root_b);
	}
}

bool find(vector<int>& A,int a,int b)
{
	if(root(A,a) == root(A,b))
	{
		return true;
	}
	return false;
}

int main()
{
	int N = 10;

	vector < int > A(N);
	vector < int > s(N);

	intialize(A,s);

	weighted_union(A,s,2,1);
	weighted_union(A,s,4,3);
	weighted_union(A,s,8,4);
	weighted_union(A,s,9,3);
	weighted_union(A,s,6,5);

	for(auto& y: A)
	{
		cout<<y<<" ";
	}

	cout<<endl;

	if(find(A,2,3))
	{
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}

	return 0;
}