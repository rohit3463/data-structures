#include<iostream>
#include<vector>

using namespace std;

void print_after_k_rotation(vector < int >& A, int n, int k)
{
    int low = k % n;
    int high = (k % n) + n;

    for(int i = low; i<high; i++)
    {
        cout<<A.at(i)<<" ";
    }
    cout<<endl;
}

int main()
{
    int n, rot, Q;

    cin>>n;
    vector < int > A(2*n);

    for(int i=0;i<n;i++)
    {
        cin>>A.at(i);
        A[i+n] = A.at(i);
    }

    cin>>Q;

    while(Q--)
    {
        cin>>rot;

        print_after_k_rotation(A, n, rot);
    }
    return 0;
}