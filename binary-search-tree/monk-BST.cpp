#include <iostream>
#include <cmath>
#include <string>

typedef unsigned long long ll ;

using namespace std;

void printNode(ll t, ll x, ll k) {
    ll l = ceil( log((double)k + 1.0) / log(2.0) ), a;

    if(t - l == 0)
        a = x;
    else 
        a = x + pow(2, t-l-1) - 1;
        
    ll d = pow(2, t-l);
    ll n = k - pow(2, l-1) + 1;

    cout<<(a + (n-1)*d);
}

void printPath(ll start, ll end, ll& val, ll& x, string& s) {
    if(start >= end)
        return;
    
    ll mid = (start + end) / 2;
    ll temp = mid / 2;

    if(x+temp > val) {
        s = s + "l";
        printPath(start, mid-1, val, x, s);
    }
    
    else if(x+temp < val) {
        s = s + "r";
        printPath(mid+1, end, val, x, s);
    }
    
    return;
}

ll findX(ll l, ll s) {
    double n = (pow(2, l) - 2) / 2;
    double x = ( (2*s) - (pow(n, 2) * 2) + 1 ) / ((2*n) + 1);

    ll t = ceil(++x)/2;
    //t = t+1;
    
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l, s, q,x;

    cin>>l>>s>>q;
    
    if(l == 1)
    {x = s+1;}

    else x = findX(l, s);
    
    while(q--) {
        ll type, k;

        cin>>type>>k;

        ll n = pow(2, l) - 1;

        string str = "";

        if(type == 0) {
            if( ((n-1)/4)+x == k )
                cout<<"root";
            else {
                printPath(0, n-1, k, x, str);
                cout<<str;
            }
        }
        else
            printNode(l, x, k);

        cout<<endl;
    }

    return 0;
}