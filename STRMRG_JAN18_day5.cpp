#include <bits/stdc++.h>
//Not complete

using namespace std;

int main(){
	int t,n,m;
	string a,b;
	cin>>t;
	while(t--){
		cin>>n>>m;
		cin>>a>>b;
		string result="";
		result+=a[0];
		int i=1, k=1, j=0, count=0;
		while(i<n && j<m){
			if(a[i]==result[k-1]){
				cout<<"Reached 1\n";
				result += a[i++];
				k++;
			}
				
			
			else if(b[j] == result[k-1]){
				cout<<"Reached 2\n";
				result += b[j++];
				k++;	
			}

			else{
				cout<<"Reached 3\n";
				result+= a[i++];
				k++;
				count++;
			}
		}

		/*if(i==n && k!=m+n){
			i--;
			cout<<"Reached X\n";
			while(b[j]==result[k-1] && j<m){
				result+=b[j++];
				k++;
			}
			result+=a[i++];
			k++;
		}

		if(j==m && k!=m+n){
			j--;
			cout<<"Reached Y\n";
			while(a[i]==result[k-1] && i<n){
				result += a[i++];
				k++;
			}
			result+=b[j++];
			k++;
		}*/

		while(i<n && k!=m+n){
			cout<<"Reached 4\n";
			if(a[i]!=result[k-1])
				count++;
			result+= a[i++];
			k++;
		}
		while(j<m && k!=m+n){
			cout<<"Reached 5\n";
			if(result[k-1] != b[j])
				count++;
			result += b[j++];
			k++;
		}

		cout<<result<<endl;
		cout<<1+count<<endl;
	}
}