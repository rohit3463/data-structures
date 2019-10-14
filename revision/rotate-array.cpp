#include<iostream>
#include<vector>

using namespace std;

vector < int > rotate( vector < int > & A, int n , int rot)
{
    // rotate n % rot times

    rot = rot%n;
    vector<int>::iterator it = A.begin();

    for(int i = rot;i>0;i--)
    {
        A.push_back(*it);
        A.erase(it);
    }

    return A;
} 

int main()
{
    int n, rot, temp;
    cin>>n;

    vector < int > V;

    for(int i=0;i<n;i++)
    {
        cin>>temp;
        V.push_back(temp);
    }
    cin>>rot;

    vector < int > S = rotate(V, n, rot);

    for(auto & y: S)
    {
        cout<<y<<" ";
    }
    cout<<endl;

    return 0;

}