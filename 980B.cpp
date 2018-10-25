#include<iostream>
using namespace std;

char a[4][100];

int main(){
	int n, k;
	bool flag = false;
	cin>>n>>k;
	for(int i=0; i<4; ++i)
		for(int j=0; j<n; ++j)
			a[i][j] = '.';

	//cout<<"B1\n";
	if (k%2 == 0 || k%(n-2) == 0){
		cout<<"YES\n";
		flag = true;
	}

	else
		cout<<"NO\n";

	

	if(flag){
		//cout<<"B2\n";
		
		if(k%2 == 0){
			for(int j=1; j<=k/2; ++j){
				a[1][j] = '#';
				a[2][j] = '#';
			}
		}
		else{
			if(k==n-2){
				for(int j=1; j<=n-2; ++j)
					a[1][j] = '#';
			}
			else{
				for(int j=1; j<=n-2; ++j){
					a[2][j] = '#';
					a[1][j] = '#';
				}
			}
		}

		for(int i=0; i<4; ++i){
			for(int j=0; j<n; ++j){
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}


}