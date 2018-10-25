#include <bits/stdc++.h>
using namespace std;

int m,c;
int price[22][22];
int memo[204][22];


//To convert complete search solution into memoisation
//base cases will be 1 more
//Now if element is precalculated(i.e memo(state)!=-1) then simply
//return the element
//else calculate it recursively and store it into memo table.
int shop(int money,int g){
	if(money<0)
		return -999;
	if(g==c)
		return m-money;
	if(memo[money][g] != -1)
		return memo[money][g];
	
	int ans=-1;
	for(int i=1; i<c; ++i)
		ans =  max(ans,shop(money-price[g][i], g+1));
	return memo[money][g] = ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>m>>c;
		memset(memo, -1 , sizeof memo);
		for(int i=0; i<c; ++i){
			cin>>price[i][0];
			for(int j=1; j<=price[i][0]; j++)
				cin>>price[i][j];
		}
		int ans=shop(m,0);
		if(ans<0) cout<<"no solution\n";
		else cout<<shop(m,0)<<"\n";
	}
}