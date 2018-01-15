#include<bits/stdc++.h>
using namespace std;

char a[15];

int main(){
	int n;
	cin>>n;
	string result = "";
	scanf("%s", a);
	for(int i=0; i<n; ++i){
		if(a[i]!='1' && a[i]!='0'){
			if(a[i]=='4')
				result+="322";
			else if(a[i]=='6')
				result+="35";
			else if(a[i]=='8')
				result+="2227";
			else if(a[i]=='9')
				result+="7332";
			else
				result+=a[i];
		}
	}
	sort(result.begin(), result.end());
	for(int i=result.size()-1; i>=0; --i)
		cout<<result[i];
	cout<<endl;
}