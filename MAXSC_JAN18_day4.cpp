//Done

#include <bits/stdc++.h>

using namespace std;

long a[701][701];

bool getmax(int i, long* temp, int n){
	int flag=0;
	long c=-1;
	for(int j=0; j<n; ++j)
		if(a[i][j]>c && a[i][j]<(*temp)){
			c = a[i][j];
			flag=1;
		}
	if(flag){
		*temp = c;
		return true;
	}
	else
		return false;
}

int main(){
	int t,n,flag=1;

	cin>>t;
	while(t--){
		long sum=0, temp=9999999999;
		cin>>n;
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				cin>>a[i][j];
		for(int i=n-1; i>=0; --i){
			if(getmax(i, &temp, n))
				sum+=temp;

			else
				flag=0;
			//cout<<"sum="<<sum<<endl;
		}
		if(flag)
			cout<<sum<<"\n";
		else{
			cout<<-1<<"\n";
			flag=1;
		}
	}
}