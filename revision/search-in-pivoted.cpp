#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find_pivot(vector < int >& A)
{
    int previous = INT8_MIN;
    for(int i=0;i<A.size();i++)
    {
        if(A.at(i)<=previous)
        {
            return i-1;
        }
        previous = A.at(i);
    }
}

int binary_search(vector< int > A, int key, int l, int r)
{
    int lower = l;
    int higher = r;

    while(higher>= lower)
    {
        int mid = int((lower + higher)/2);
        if(A[mid] == key)
        {
            return mid;
        }
        else if(A[mid] > key)
        {
            higher = mid - 1;
        }
        else
        {
            lower = mid + 1;
        }
    }

    return INT8_MIN;
}

void find_key(vector < int > & A, int pivot, int key)
{   
    int lower_result = binary_search(A, key, 0 , pivot);
    int higher_result = binary_search(A, key, pivot+1, A.size()-1);

    if(lower_result != INT8_MIN)
    {
        cout<<"Key found at index :"<<lower_result<<endl;
    }
    else if(higher_result != INT8_MIN)
    {
        cout<<"Key found at index :"<<higher_result<<endl;

    }
    else
    {
        cout<<"Key Not Found!!!";
    }

}

int main()
{
    int n, temp, key;
    cin>>n;
    vector < int > A;

    for(int i=0;i<n;i++)
    {
        cin>>temp;
        A.push_back(temp);
    }
    cin>>key;
    int pivot = find_pivot(A);
    cout<<"Pivot at index :"<<pivot<<endl;

    find_key(A, pivot, key);
    return 0;
}