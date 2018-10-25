#include<bits/stdc++.h>
using namespace std;

int a[10005];
//int flag[10005];

int main(){
	int n,k;
	cin>>n>>k;
	//memset(flag, -1, sizeof flag);
	for(int i=0; i<n; ++i)
		cin>>a[i];
	while(k!=0){
	for(int i=n-1; i>=0; --i){
		if(k==0)
			break;
		if(k>0  && a[i]<0){
			a[i]=abs(a[i]);
			//flag[i]=1;
			k--;
		}
	}
	cout<<"k= "<<k <<endl;
	for(int i=0; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
	if(k!=0){
		for(int i=0; i<n; ++i){
			if(k==0)
				break;
			if(k>0){
				a[i]=a[i]*(-1);
				k--;
			}
		}
	}
	cout<<"k= "<<k <<endl;
	for(int i=0; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
	}
	int sum=0;
	for(int i=0; i<n; ++i)
		sum+=a[i];
	cout<<sum<<"\n";

}