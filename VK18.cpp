#include<bits/stdc++.h>

using namespace std;
int diff[11] = {2,8,14,20,17,-10,-6,0,6,30,11};
long result[1000001];
int main(){
	int t,n;
	cin>>t;
	result[0] = 2;
	for(int i=1; i<1000001; ++i)
		result[i] = result[i-1]+diff[i%11];
	/*for(int i=1; i<1000001; ++i)
		result[i]+=result[i-1];*/
	for(int i=0; i<30; ++i)
		cout<<result[i] <<" ";

	/*while(t--){
		cin>>n;
		cout<<result[n-1]<<"\n";
	}*/	

	
}