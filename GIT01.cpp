#include<bits/stdc++.h>

using namespace std;
char a[101][101], temp1[101][101];

int main(){
	int t,n,m,cost1=0,cost2=0;

	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				cin >> a[i][j];
				//temp1[i][j] = a[i][j];
				//temp2[i][j] = a[i][j];
			
		
			for(int i=0; i<n; ++i){
				for(int j=0; j<m; ++j){
					if(i%2==0){
						if(j%2!=0 && a[i][j] != 'G'){
							//cout<<a[i][j];
							//a[i][j] = 'G';
							cost1+=5;
						}
						if(j%2==0 && a[i][j] != 'R'){
							//cout<<a[i][j];
							cost1+=3;
						}
					}
					if(i%2!=0){
						if(j%2==0 && a[i][j] != 'G'){
							//cout<<a[i][j];
							cost1+=5;
						}
						if(j%2!=0 && a[i][j] != 'R'){
							//cout<<a[i][j];
							cost1+=3;
						}
					}
				
			}
			//cout<<endl;
			}


		
			for(int i=0; i<n; ++i)
				for(int j=0; j<m; ++j){
					if(i%2 == 0){
						if(j%2!=0 && a[i][j] != 'R')
							cost2+=5;
						if(j%2==0 && a[i][j] != 'G')
							cost2+=3;
					}
					if(i%2!=0){
						if(j%2==0 && a[i][j] != 'R')
							cost2+=5;
						if(j%2!=0 && a[i][j] != 'G')
							cost2+=3;
					}
				}
		cout << min(cost1,cost2)<<endl;
		cost1=0;
		cost2=0;
	}
}
