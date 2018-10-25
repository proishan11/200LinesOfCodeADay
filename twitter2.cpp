#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll m, n;
    cin>>m>>n;
    ll dp[m][n];

    //memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(ll i=1; i<n; ++i){
        dp[0][i] = 1;
    }

    for(ll i=1; i<m; ++i){
        dp[i][0] = 1;
    }

    /*for(ll i=0; i<m; ++i){
        for(ll j=0; j<n; ++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/


    for(ll i=1; i<m; ++i){
        for(ll j=1; j<n; ++j){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];

        }
    }

    cout<<dp[m-1][n-1]<<endl;
    return 0;
}
