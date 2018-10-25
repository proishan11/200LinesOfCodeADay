#include<iostream>
using namespace std;
int main(){
	string a;
	cin>>a;
	int counto=0, countd=0;
	for(int i=0; i<a.size(); ++i)
		if(a[i]=='-')
			countd++;
		else
			counto++;
	if(counto == 0){
		cout<<"YES\n";
		return 0;
	}
	if(countd%counto==0)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}