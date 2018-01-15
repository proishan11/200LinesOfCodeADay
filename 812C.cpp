#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,s;
int a[100009];
ll b[100009];


ll calc(int k){
	for(int i=0; i<n; i++)
		b[i]=a[i]+(i+1)*(ll)k;
	sort(b,b+n);
	ll sum = 0;
	for(int i=0; i<k; i++)
		sum+=b[i];
	return sum;
}

int main(){
	cin>>n>>s;
	for(int i=0; i<n; ++i)
		cin>>a[i];
	
	//In binary Search always initialize like this.
	int i=0,j=n+1,k;
	//and compare like this
	//because if i=j then loop will not run thus that case left out.
	while(i<j-1){
		k = (i+j)/2;
		if(calc(k)<=s)
			i=k;
		else
			j=k;
	}
	cout<<i<<' '<<calc(i)<<'\n';
}