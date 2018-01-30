#include<bits/stdc++.h>
using namespace std;

int dp[100005][3];
long a[100005];
long height[100005];

//0 means no cut (always possible)
//1 means left cut (x(i)-h(i) > x(i-1))
//2 means right cut (x(i)+h(i) < x(i+1))
//WA on some test cases

int main(){
    bool flag=false;
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>a[i]>>height[i];

    //if no cut then intitially count = 0
    dp[0][0]=0;
    //if cut left 1st cut always possible
    dp[0][1]=1;
    //check if right cut is possible or not
    if(a[0]+height[0]<a[1])
        dp[0][2] = 1;
    else
        dp[0][2] = 0;

    for(int i=1; i<n; ++i){
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]) );
        if(a[i]-height[i] > a[i-1]){
            dp[i][1] = max(dp[i-1][0]+1, max(dp[i-1][1]+1, dp[i-1][2]+1));
            flag=true;
        }
        if(i<n-1)
            if(a[i]+height[i] < a[i+1])
                dp[i][2] = max(dp[i-1][0]+1, max(dp[i-1][1]+1, dp[i-1][2]+1));
    }
    dp[n-1][2] = max(dp[n-2][0]+1, max(dp[n-2][1]+1 , dp[n-2][2]+1) );

    cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<<endl;
}
