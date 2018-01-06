#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

long sigma[MAX];

void genrate(){
	sigma[0] = 1;
	sigma[1] = 3;
	for(int i=2; i<MAX; ++i){
		sigma[i] = sigma[i-1]+i+1;
	}
}

int find_for(long partition_sum, int start, int end){
	int mid = (start+end)/2;
	//cout<<mid<<endl;
	//cout<<sigma[mid]<<"sigmamid\n";
	if(start<end){
		//cout<<"Reached1\n";
		if(sigma[mid]==partition_sum)
			return mid;
		else if(sigma[mid] > partition_sum){
			find_for(partition_sum, start, mid-1);
			//cout<<"Reached2\n";
		}
		else{
			find_for(partition_sum, mid+1, end);
			//cout<<"Reached3\n";
		}
	}
	else
		return mid-1;

}

int main(){
	genrate();
	//cout << sigma[find_for(25, 0, MAX)]<<endl;
	int t, n, x;
	
	cin>>t;
	while(t--){
		cin>>x>>n;
		int result[n];
		long numr = n*n + n - 2*x;
		if((numr)%4 != 0 || n==2)
			cout<<"impossible\n";
		else{
			long partition_sum = numr/4;
			//cout<<"partition_sum "<<partition_sum<<endl;
			int index = find_for(partition_sum+x, 0, MAX-1), index2;
			while(sigma[index]<=partition_sum+x)
				index++;
			//cout<<sigma[index]<<endl;
			int remain = sigma[index]- x - partition_sum;
			//cout<<"remain= "<<remain<<endl;
			if(remain!=x){
				for(int i=0; i<=index; ++i)
					result[i]=0;
				
				for(int i=index+1; i<n; ++i)
					result[i] = 1;
				result[remain-1]=1;
				result[x-1] = 2;
			}
			else{
				//cout<<"reached here"<<endl;
				index2 = find_for(x,0,MAX-1);
				while(sigma[index2]<x)
					index2++;
				int remain2 = sigma[index2]-x;
				for(int i=0; i<=index2; ++i)
					result[i] = 0;
				for(int i=index2+1; i<n; ++i)
					result[i]=1;
				result[remain2-1]=1;
				result[x-1]=2;
				//cout<<sigma[index2]<<endl;
			}

			for(int i=0; i<n; ++i)
				cout<<result[i];
			cout<<"\n";
		}
	}
}