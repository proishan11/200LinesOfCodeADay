#include<iostream>

using namespace std;

long long dp[101][101];

int main(){
	int n, m;
	dp[0][0] = 1;
	for(int n=1; n<=100; ++n){
		dp[n][0] = 1;
		for(int m=1; m<=n; ++m){
			dp[n][m] = dp[n-1][m] + dp[n-1][m-1];
		}
	}

	while(1){
		cin>>n>>m;
		if(n==0 && m==0)
			return 0;
		cout<<dp[n][m]<<endl;
	}

}
