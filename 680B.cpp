#include<bits/stdc++.h>
using namespace std;

int X[1004];

int main(){
	int n, a;
	cin>>n>>a;
	for(int i=0; i<n; ++i)
		cin>>X[i];

	int ans = 0;

	ans += X[a-1];

	int end = min(a-1, n-a);
	
	for(int d=1; d<=end; ++d){
		
		if(X[a-d-1] == 1 && X[a-1+d] == 1)
			ans+=2;
	}
	
	if(a<=n/2){
		
		for(int i=2*a-1; i<n; ++i){
			if(X[i] == 1)
				ans++;
		}
	}
	else{
		
		for(int i=0; i<2*a-n-1; ++i){
			if(X[i] == 1)
				ans++;
		}
	}


	cout<<ans<<endl;

}