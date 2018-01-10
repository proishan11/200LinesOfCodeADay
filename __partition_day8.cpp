#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
long sigma[MAX];
int result[MAX];

void genrate(){
	sigma[0] = 1;
	sigma[1] = 3;
	for(int i=2; i<MAX; ++i){
		sigma[i] = sigma[i-1]+i+1;
	}
	//cout<<"done\n";
	return;
}

int find(long sum, int n){
	int l=0, r=n-1, m;
	while(l<=r){
		m = l+(r-l)/2;
		//cout<<sigma[m]<<endl;
		if(sigma[m] == sum)
			return m;
		if(sigma[m] < sum)
			l=m+1;
		else
			r = m-1;
		//cout<<m <<" " <<l <<" "<<r<<"\n";
	}
	//cout<<"Reached here\n";
	while(sigma[m]<sum)
		++m;
	return m; 
}

void printresult(int n, long partition_sum){
	long sum=0;
	for(int i=0; i<n; ++i){
		if(result[i] == 0)
			sum+=i+1;
		cout<<result[i];
	}
	cout<<"\n";
	cout<<"sum = "<<sum<<endl;
	cout<<"part = "<<partition_sum/4<<endl;
}

void partition(long sum, int x, int inc, int n){
	int index = find(sum+x, n);
	//cout<<"inc = "<<inc<<endl; 
	//cout<<"index = "<<index<<endl;
	//for(int i=0; i<n; ++i)
	//	cout<<result[i];
	//cout<<endl;
	if(sigma[index] == sum){
		//cout<<"Reached Equal\n";
		if(inc%2!=0)
			for(int i=0; i<=index; ++i)
				result[i] = 0;
		
		else
			for(int i=0; i<=index; ++i)
				result[i] = 1;
		//printresult(n);
		return;
	}
	else{
		//cout<<"Reached Unequal\n";
		if(inc%2==0)
			for(int i=0; i<=index; ++i)
				result[i] = 1;
		else
			for(int i=0; i<=index; ++i)
				result[i] = 0;
		//printresult(n);
		
		partition(sigma[index]-sum, 0, ++inc, n);
	}
}

int main(){
	genrate();
	int t, n, x;
	long partition_sum;
	//cout<<find(57,14)<<endl;
	cin>>t;
	while(t--){
		cin>>x>>n;
		for(int i=0; i<n; ++i)
			result[i] = 1;
		partition_sum = (n*n + n -2*x);
		//cout<<partition_sum/4<<endl;
		if(partition_sum % 4 == 0 && n>2){
			//cout<<"Here\n";
			partition(partition_sum/4+x, x, 1, n);
			result[x-1] = 2;
			printresult(n, partition_sum);
		}
		else
			cout<<"impossible\n";
	}
}