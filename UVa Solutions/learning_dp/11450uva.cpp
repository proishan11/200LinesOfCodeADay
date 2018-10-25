#include <bits/stdc++.h>
/*Done*/
using namespace std;

int m,c;
int price[22][22];
//int memo[204][22];

int shop(int money,int g){
	
	//If money gets zero in between return -ve value
	if(money<0)
		return -999;
	//if g==c-1(last garment) is processed and now g=c so return the ammount spent
	if(g==c)
		return m-money;
	//for each garment g we have k(price[g][0]) choices of models so we try'em all and take the maximum
	int ans=-1;
	for(int i=1; i<=price[g][0]; ++i)
		ans =  max(ans,shop(money-price[g][i], g+1));
	
	//finally return the ans
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>m>>c;
		for(int i=0; i<c; ++i){
			cin>>price[i][0];
			for(int j=1; j<=price[i][0]; j++)
				cin>>price[i][j];
		}
		
		cout<<shop(m, 0)<<endl;
	}
}
