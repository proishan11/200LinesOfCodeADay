#include<iostream>
#include<vector>
using namespace std;

long a[100001],b[100001],diff[100001];

int main(){
	int n,max1,max2;
	long max=-1,sum=0;
	cin >> n;
	
	for(int i=0; i<n; ++i)
		cin>>a[i];
	
	for(int i=0; i<n; ++i){
		cin>>b[i];
		diff[i] = b[i]-a[i];
	}
	//max=diff[0];
	for(int i=0; i<n; ++i){
		if(max<a[i]){
			max1=i;
			max=a[i];
		}
		if(max==a[i]){
			if(diff[i]>diff[max1])
				max1 = i;
		}
	}

	max=-1;

	for(int i=0; i<n; ++i){
		if(max<a[i]){
			max = a[i];
			if(i != max1)
				max2 = i;
		}
		if(max == a[i]){
			if(diff[i] > diff[max2])
				if(i != max1)
					max2 = i;
		}
	}
	cout<<max1 <<" " <<max2<<endl;

	for(int i=0; i<n; ++i){
		if(i!=max1 && i!=max2)
			sum+=a[i];
	}
	if(sum<= diff[max1] + diff[max2])
		cout<<"YES";
	else
		cout<<"NO";
	

}