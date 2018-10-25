#include<iostream>
#include<math.h>

using namespace std;

int main(){
	int t,count=0;
	long y;
	double x;
	cin>>t;
	while(t--){
		cin >> y;
		for(int i=700; i>=1; --i){
			x = sqrt(y-i);
			if(static_cast<int>(x/static_cast<int>(x)) == 1)
				count+=x;
		}
		cout<<count<<"\n";
		count=0;
	}
}