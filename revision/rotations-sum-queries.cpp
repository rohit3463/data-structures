#include<iostream>
#include<vector>

using namespace std;

void rotate_right(vector < int >& A, int & l, int & r, int rot, int n)
{
    rot = rot%n;
    int right_left;
    if((r + rot) < A.size() )
    {
        l = l + rot;
        r = r + rot;
    }
    else
    {
        right_left = A.size() - 1 - rot;
        rot -= right_left;

        l = rot;
        r = l + n;
    }
    for(int i =l;i<r;i++)
    {
        cout<<A.at(i)<<" ";
    }
    cout<<endl;
}

void rotate_left(vector < int >& A, int & l, int & r, int rot, int n)
{
    rot = rot%n;
    int left_left;
    if((l - rot)>=0)
    {
        l = l - rot;
        r = r - rot;
    }
    else
    {
        left_left = l;
        rot -= left_left;
        r = A.size() - 1 - rot;
        l = r - n -1;
    }
    for(int i =l; i<r ;i++)
    {
        cout<<A.at(i)<<" ";
    }
    cout<<endl;
}

int return_sum(vector < int >& prefix_sum_arr, int l, int low, int high)
{   
    int n = prefix_sum_arr.size()/3;
    if(low < 0 || high > n)
    {
        cout<<"Invalid Range Arguments! Array Length : "<<n<<endl;
        return 0;
    }
    if(l + low == 0)
    {
        return prefix_sum_arr.at(high);
    }
    else
    {
        return prefix_sum_arr.at(l + high) - prefix_sum_arr.at(l + low - 1);
    }
}

int main()
{
    int n, temp, Q, low, high, l, r, rot, type;
    cin>>n;
    vector < int > A(3*n);

    for(int i = 0; i<n;i++)
    {
        cin>>temp;
        A.at(i) = temp;
        A.at(i+n) = temp;
        A.at(i+ 2*n) = temp;
    }
    vector < int > prefix_sum_arr;
    int sum = 0;
    for(auto & y: A)
    {   
        sum += y;
        prefix_sum_arr.push_back(sum);
    }
    cin>>Q;

    l = n;
    r = 2 * n;

    while(Q--)
    {
        cin>>type;
        if(type == 1)
        {
            cin>>rot;
            rotate_left(A, l, r, rot, n);
        }
        else if(type == 2)
        {
            cin>>rot;
            rotate_right(A, l, r, rot, n);
        }
        else
        {
            cin>>low,
            cin>>high;
            cout<<return_sum(prefix_sum_arr, l, low, high);
        }
    }

    return 0;
}