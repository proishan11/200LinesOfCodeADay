#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k, count, sum, maxc=0;
    cin>>n;
    int a[n];
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    cin>>k;
    sum=0; count=0;
    for(int i=0; i<n; ++i){
        if(sum+a[i] <= k){
            sum+=a[i];
            count++;
        }
        else if(sum!=0){
            sum = sum-a[i-count]+a[i];
        }
        maxc = max(count, maxc);
    }
    /*sort(a,a+n);
    sum = 0;
    count = 0;

    for(int i=0; i<n; ++i){

        sum += a[i];
        cout<<a[i]<<" " <<sum<<" "<<count<<endl;
        if(sum<=k)
            count++;
        else
            break;
    }*/

    cout<<maxc<<endl;
}
