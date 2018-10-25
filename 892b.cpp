#include<iostream>
using namespace std;


int main(){
	int n,result=0,count=0;
	cin >> n;
	long a[n],mi=99999999;
	long killed[n] = {0};
	for(int i=0; i<n; ++i)
		cin>>a[i];
	for(int i=n-1; i>=0; --i){
		mi = min(mi, i-a[i]);
		if(count==0){
			count=1;
			for(int j=i-a[i]; j<i; ++j)
				killed[j] = 1;
		}

		if(i-a[i]<=mi && count==1){
		for(int j=i-a[i]; j<i; ++j)
			killed[j] = 1;
			
		}
	}
	for(int i=0; i<n; ++i){
		if(killed[i]!=1){result++;}
	}
	cout<<result<<"\n";
}