#include<iostream>
#include<unordered_map>
#include<set>

using namespace std;

int main(){

	int arr[] = {3, 3, 3, 4, 4, 2};
	int k =4;
	int n = sizeof(arr)/sizeof(int);

	unordered_map<int, int> m;
	set<int> s;

	for(int i=0; i<k; i++){

		if(m.find(arr[i]) != m.end())
			m[arr[i]]++;
		else
			m[arr[i]] = 1;

		if(m[arr[i]] == 1)
			s.insert(arr[i]);

		else {
			if(!s.empty())
				s.erase(arr[i]);
		}
	}
	if(!s.empty())
		cout<<(*s.rbegin())<<endl;
	else
		cout<<"Nothing"<<endl;

	for(int i=k;i<n;i++){

		if(m.find(arr[i]) != m.end())
			m[arr[i]]++;
		else
			m[arr[i]] = 1;

		if(m[arr[i]] == 1)
			s.insert(arr[i]);

		else {
			if(!s.empty())
				s.erase(arr[i]);
		}
		--m[arr[i-k]];
		if( m[arr[i-k]]== 1)
			s.insert(arr[i-k]);

		else {
			if(!s.empty())
				s.erase(arr[i-k]);
		}

		if(!s.empty())
			cout<<(*s.rbegin())<<endl;

		else cout<<"Nothing"<<endl; 

	}

	return 0;
}