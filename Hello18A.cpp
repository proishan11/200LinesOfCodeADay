#include<bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, int m)
{
    long long temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2,m);       
    if (y%2 == 0)
        return temp*temp;
    else
    	if(x*temp*temp<m)
    		return x*temp*temp;
    	else
    		return m;
        
    
}  

int main(){
	int n,m;
    while(scanf("%d %d",&n,&m)==2)
	   cin>>n>>m;
	cout<<m%power(2,n,m)<<endl;
}