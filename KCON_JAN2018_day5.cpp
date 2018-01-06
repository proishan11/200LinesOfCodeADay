#include<bits/stdc++.h>
using namespace std;
 
int x[100000];

long long max(long long a, long long b){
        return a>b?a:b;
}

long long maxSubArraySum(int arr[], int n){
        long long max_so_far=arr[0];
        long long max_till_here=arr[0];
        for(int i=1;i<n;i++){
                max_till_here=max(arr[i],max_till_here+arr[i]);
                max_so_far=max(max_till_here,max_so_far);
        }
        return max_so_far;
}

int minimum(int a[], int size){
	int m=-9999999;
	for(int i=0; i<size; ++i)
		m = max(a[i],m);
	return m;
}

int main(){
	int t, n, k;
	cin>>t;
	while(t--){
		int flagp=1, flagn=1;
		long long sum=0,result=0;
		cin>>n>>k;
		int temp[2*n], rev[n];
		for(int i=0; i<n; ++i){
			cin>>x[i];
			if(x[i]>0)
				flagn=0;
			if(x[i]<0)
				flagp=0;
			sum+=x[i];
			temp[i]=x[i];
			rev[n-i-1] = x[i];
		}
		for(int i=n; i<2*n; ++i)
			temp[i] = x[i-n];
		long long single = maxSubArraySum(x,n);
		long long doub = maxSubArraySum(temp, 2*n);
		if(flagp)
			{cout<<k*single<<endl; continue;}
		if(flagn)
			{cout<<minimum(x,n)<<endl; continue;}
		if(k==1)
			{cout<<single<<endl; continue;}
		if(k==2)
			{cout<<doub<<endl; continue;}

		if(sum==single){cout<<k*sum<<endl; continue;}
		long long max1=-1, max2=-1, t1, t2;
		for(int i=0; i<n; ++i){
			t1=x[n-i-1];
			max1=max(t1,max1);
			t2=x[i];
			max2=max(t2,max2);
		}
		cout<<max(sum*(k-2)+max1+max2, max(doub,max(single,sum*k)))<<endl;
	}
}