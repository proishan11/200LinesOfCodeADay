//DONE

#include<bits/stdc++.h>

using namespace std;
int main(){
	int n;
	cin>>n;
	string s, ans;

	cin>>s;

	ans = s[s.length()-1];
	for(int i=s.length()-2; i>=0; --i){
		int len = ans.length();
		int index=0;
		if(len/2 != 0)
			index = len/2;
		
		if(index>0){
			
			string temp = ans.substr(index, ans.length()-1);
			string temp1 = ans.substr(0, index);
			
			ans = temp1 + s[i] + temp; 

		}
		else
			ans = s[i]+ans;
		//cout<<ans<<endl;
	}


	cout<<ans<<endl;
}