/*Done*/

#include<bits/stdc++.h>

using namespace std;
char a[101][101];


int main(){
	int t,n,m,c1,c2;
	cin>>t;
	while(t--){
		int cost1[2]={0};
		int cost2[2]={0};
		cin>>n>>m;
		
		for(int i=0; i<n; ++i)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
			
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j){
				if((i+j)%2==0 && a[i][j]!='G')
					cost1[0]++;
				if((i+j)%2!=0 && a[i][j]!='R')
					cost1[1]++;
			}

		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j){
				if((i+j)%2!=0 && a[i][j]!='G')
					cost2[0]++;
				if((i+j)%2==0 && a[i][j]!='R')
					cost2[1]++;
			}

		c1 = 5*cost1[0]+3*cost1[1];
		c2 = 5*cost2[0]+3*cost2[1];
		cout<<min(c1,c2)<<endl;
	}
}