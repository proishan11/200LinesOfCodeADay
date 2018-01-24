#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int price[MAX];
int memo[MAX];
//int a=0, b=0;

int rod_cut(int n){
    if(memo[n-1]>=0) { return memo[n-1]; }
    int m;
    if(n==0)
        m=0;
    else{
        m = -1;
        //cout<<"call = "<<++a<<endl;
        /* i is the length of rod cut the price will be computed recursively as
        below for each value of i from 0 to n-1
        we memoize this computation so that for i=1,2,--, n
        we can directly view in the memo table*/

        for(int i=0; i<n; ++i){
            //cout<<"Reached here "<< ++b << " i = " << i << " n-i-1 = " << n-i-1 << endl;
            m = max(m, price[i] + rod_cut(n-i-1));
            //cout<<"m = "<<m<<endl;
        }
    }
    memo[n-1] = m;
    //cout<<"m = "<<m<<endl;
    return m;
}

int main(){
    int n;
    cout<<"Enter length of rod\n";
    cin>>n;
    //memset(memo, -1, n+1);
    for(int i=0; i<n; ++i)
        memo[i] = -1;

    cout<<"Enter the price array \n";
    for(int i=0; i<n; ++i)
        cin>>price[i];
    int result = rod_cut(n);
    cout<<result<<endl;

}
