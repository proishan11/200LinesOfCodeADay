/* DONE */

#include<bits/stdc++.h>
using namespace std;

int a[1004];

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; ++i)
		cin>>a[i];

	int current_max = -1;

	for(int i=0; i<n; ++i){
		int current_val = 1;
		for(int j=i-1; j>=0; --j){
			if(a[j]>a[j+1])
				break;
			else
				current_val++;
		}

		for(int j=i+1; j<n; ++j){
			if(a[j]>a[j-1])
				break;
			else
				current_val++;

		}

		current_max = max(current_max, current_val);

	}

	cout<<current_max<<endl;
}