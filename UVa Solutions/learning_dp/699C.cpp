#include<bits/stdc++.h>
using namespace std;

//Done

int dp[105][3];
int a[105];

int main(){
    int n;
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>a[i];
    int day = 0;
    for(int j=0; j<3; ++j)
        dp[day][j] = 0;
    for(int i=0; i<n; ++i){
        if(a[i]==0)
            dp[i+1][0] = max(dp[i][0], max(dp[i][1], dp[i][2]));
        if(a[i]==1){
            dp[i+1][1] = max(dp[i][0]+1, dp[i][2]+1);
            dp[i+1][0] = max(dp[i][0], max(dp[i][1], dp[i][2]));
        }
        if(a[i]==2){
            dp[i+1][2] = max(dp[i][0]+1, dp[i][1]+1);
            dp[i+1][0] = max(dp[i][0], max(dp[i][1], dp[i][2]));
        }
        if(a[i]==3){
            dp[i+1][0] = max(dp[i][0], max(dp[i][1], dp[i][2]));
            dp[i+1][1] = max(dp[i][0]+1, dp[i][2]+1);
            dp[i+1][2] = max(dp[i][0]+1, dp[i][1]+1);
        }
    }
    cout<<n-max(dp[n][0],max(dp[n][1], dp[n][2]))<<endl;
}
