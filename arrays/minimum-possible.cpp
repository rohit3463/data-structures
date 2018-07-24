#include<iostream>
#include<algorithm>
#include<climits>
#include<unordered_map>

using namespace std;

void pairs(int arr[], int size, int k){

    unordered_map<int, int> m;
    int total_pairs = 0,closet;
    int abs_min = INT_MAX, min =INT_MAX;

    for(int i=0; i<size; i++){
        if(m.find(arr[i]) != m.end())
            m[arr[i]]++;

        else m[arr[i]] = 1;
    }

    for(int i=0; i<size; i++){

        if(min > arr[i])
            min = arr[i];

        if(abs_min > abs(k-arr[i])){
            closet = arr[i];
            abs_min = abs(k-arr[i]);
        }
    }

    int min_val = min+closet - k;

    for(int i=0; i<size; i++){

        int first = k - min_val - arr[i];
        int second = k+ min_val - arr[i];

        if(first == arr[i]){

            if(m.find(first) != m.end())
                total_pairs += m[first]-1;
        }
        else {
                if(m.find(first) != m.end())
                    total_pairs += m[first];
            }

        if(second == arr[i]){

            if(m.find(second) != m.end())
                total_pairs += m[second]-1;
        }
        else {
                if(m.find(second) != m.end())
                    total_pairs += m[second];
            }
    }

    cout<<"Minimal value: "<<abs(min_val)<<endl;
    cout<<"Total pairs: "<<total_pairs/2<<endl;
}

int main(){


    int arr[] = {0, 4, 6, 2, 4};

    int size = sizeof(arr)/sizeof(int);
    int k = 7;

    pairs(arr, size, k);

    return 0;
}