#include<iostream>
#include<vector>

using namespace std;

void rotate(vector < int >& A, int n, int rot)
{
    // rotate rot%n times

    rot = rot%n;
    vector < int >:: iterator it = A.end();
    it--;

    for(int i = rot;i>0;i--)
    {
        A.insert(A.begin(), *it);
        A.pop_back();
    }
    return;
}

int main()
{
    int n, rot, temp;
    cin>>n;

    vector < int > A;

    for(int i=0; i<n;i++)
    {
        cin>>temp;
        A.push_back(temp);
    }

    cin>>rot;

    rotate(A, n, rot);

    for(auto& y: A)
    {
        cout<<y<<" ";
    }
    cout<<endl;
    return 0;
}