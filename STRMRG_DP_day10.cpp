#include <bits/stdc++.h>
using namespace std;

int DP[5001][5001];
char a[50001], b[5001];

int solve(int n, int m){
	if(m==0 && n==0)
		return 0;
	if(n==0){
		int temp_count = 0;
		for(int i=0; i<m-1; ++i)
			if(b[i]!=b[i+1])
				temp_count++;
		return temp_count;
	}

	if(m==0){
		int temp_count=0;
		for(int i=0; i<n-1; ++i)
			if(a[i]!=a[i+1])
				temp_count++;
		return temp_count;
	}

	if(a[n-1] == b[m-1])
		if(DP[n-1][m-1]!=-1)
			return DP[n-1][m-1];
		else
			DP[n-1][m-1] =  solve(n-1, m-1);
	else{
		if(DP[n-1][m-1] != -1)
			return DP[n-1][m-1];
		else
			DP[n-1][m-1] = min(1+solve(m-1,n-1), min(solve(n-1,m), solve(n, m-1)));
	}
}


int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0; i<n; ++i)
			cin>>a[i];
		for(int i=0; i<m; ++i)
			cin>>b[i];
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				DP[i][j] = -1;
		solve(n,m);
		cout<<DP[n-1][m-1]<<endl;
		/*for(int i=0; i<=n; ++i)
			for(int j=0; j<=m; ++j){
				if(i==0 && j==0){
					DP[i][j] = 0;
					continue;
				}
				if(i==n){
					int temp_count=0;
					for(int k=j-1; k<m; ++k)
						if(b[k]!=b[k+1])
							temp_count++;
					DP[i][j] = temp_count;
					continue;
				}
				if(j==m){
					int temp_count=0;
					for(int k=i-1; k<n; ++k)
						if(a[k] != a[k+1])
							temp_count++;
					DP[i][j] = temp_count;
					continue;
				}
				if(a[i-1] == b[j-1])
			}*/

	}
}