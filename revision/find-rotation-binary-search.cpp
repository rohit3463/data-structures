#include<iostream>
#include<vector>

using namespace std;

int find_rotated_index(vector < int >& A,int low, int high)
{
    int mid = int((low + high)/2);

    if(mid<high && A.at(mid)<A.at(mid-1))
    {
        return mid;
    }
    if(mid>low && A.at(mid)>A.at(mid+1))
    {
        return mid+1;
    }

    if(A[high]>A[mid])
    {
        return find_rotated_index(A, low, mid);
    }
    return find_rotated_index(A, mid, high);
}

int main()
{
    int temp, n;

    cin>>n;
    vector < int > A;

    for(int i=0;i<n;i++)
    {
        cin>>temp;
        A.push_back(temp);
    }

    cout<<find_rotated_index(A, 0, A.size()-1)<<endl;
    return 0;
}