#include<iostream>

using namespace std;

int main()
{
	int r = 5;
	int * p = new int(5);

	//int * temp = p;

	delete p;

	cout<<p;
	return 0;
}