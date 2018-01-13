#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

/*long sigma[MAX];

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

}*/

int result[MAX];

void printresult(int n){
	long long sum=0;
	for(int i=0; i<n; ++i){
		//if(result[i] == 0)
			//sum+=i+1;
		cout<<result[i];
	}
	cout<<"\n";
}

int main(){
	int t, n, x, remain;
	long long sum;
	cin>>t;

	while(t--){
		cin >> x >> n;
		for(int i=0; i<n; ++i)
			result[i]=1;
		int flag=0;
		sum = (n*n + n - 2*x);
		//cout << sum;
		if(sum%4 != 0 || n==2){
			cout<<"impossible\n";
			continue;
		}
		else{
			sum = sum/4;
			remain = sum;
			for(int i=0; i<n; ++i){

				if(i != x-1){
					//cout<<"R\n";
					result[i] = 0;
					remain = remain-i-1;
				}
				
				//printresult(n);
				if(remain == 0)
					break;
				if(remain<0){
					//cout<<"reached heare\n";
					if(abs(remain) == x){

						for(int i=0; i<x; ++i){
							result[i] = 1;
							remain = remain-i-1;
							if(remain==0){flag=1; break; }
							if(remain<0){
								result[abs(remain)-1] = 0;
								flag = 1;
								break;
								
							}
						}

					}

					else{
						//cout<<"remain = "<<remain<<endl;
						
						//cout<<"t2\n";
						result[abs(remain)-1] = 1;
						break;
					}
				}
				
				if(flag)
					break;

			}
			result[x-1] = 2;
			printresult(n);
		}
	}


	/*genrate();
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
			long partition_sum = numr/4, sum1=0,sum2=0;
			//cout<<"partition_sum "<<partition_sum<<endl;
			int index = find_for(partition_sum, 0, MAX-1), index2;
			while(sigma[index]<=partition_sum+x)
				index++;
			//cout<<sigma[index]<<endl;
			int remain = sigma[index]- x - partition_sum;
			//cout<<"remain= "<<remain<<endl;
			if(remain!=x){
				for(int i=0; i<=index; ++i){
					result[i]=0;
					sum1+=i+1;
				}
				sum1-=remain-1;
				//cout<<sum1<<endl;
				if(sum1!=partition_sum){cout<<"impossible\n"; continue;}
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
				//cout<<index2<<endl;
				int remain2 = sigma[index2]-x;
				//cout<<remain2<<endl;
				for(int i=0; i<=index2; ++i){
					result[i] = 0;
					sum1+=i+1;
				}
				//cout<<sum1<<endl;
				sum1-=remain2-1;
				//cout<<sum1<<endl;
				if(sum1!=partition_sum){cout<<"impossible\n"; continue;}
				for(int i=index2+1; i<n; ++i)
					result[i]=1;
				if(remain2>1)
					result[remain2-1]=1;
				result[x-1]=2;
				//cout<<sigma[index2]<<endl;
			}

			for(int i=0; i<n; ++i)
				cout<<result[i];
			cout<<"\n";
		}
	}*/
}