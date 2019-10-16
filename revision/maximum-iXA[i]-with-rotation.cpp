#include<iostream>
#include<vector>

using namespace std;

int find_maxi(vector < int > & A)
{   
    int maxVal = 0, arrSum =0, currVal=0;

    for(int i = 0; i<A.size();i++)
    {
        currVal += i * A.at(i);
        arrSum += A.at(i);
    }

    maxVal = currVal;

    for(int j=1;j<A.size();j++)
    {
        currVal = currVal + arrSum - A.size() * A.at(A.size()-j);

        if(currVal>maxVal)
        {
            maxVal = currVal;
        }
    }

    return maxVal;


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
    cout<<find_maxi(A)<<endl;
    return 0;
}