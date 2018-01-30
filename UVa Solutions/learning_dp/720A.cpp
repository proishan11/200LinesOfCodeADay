#include<bits/stdc++.h>
using namespace std;

int a[102][102];

void spiral(int n, int m){
    cout<<a[0][0]<<" ";
    int i=0, j=0;
    while(i<n || j<m){
        if(j<m-1) {j=j+1;}
        else {i = i+1;}
        while(j>0 && i<n){
            cout << a[i][j] << " ";
            i=i+1;
            j=j-1;
        }
        cout<<a[i][j]<<" ";
        if(i==n && j!=m)
            i--;
        //j = j+1;
        cout<<"\nReached Here"<<endl;
        cout<<"i = "<<i << "j = "<<j <<endl;
        if(i<n-1) {i=i+1;}
        else {j=j+1;}
        while(i>0 && j<m){
            cout<<a[i][j]<<" ";
            j=j+1;
            i=i-1;
        }
        if(j==m && i!=n)
            j--;
        cout<<a[i][j] <<" ";
        //i = i+1;
        cout<<"\nHere"<<endl;
        cout<<"i = "<<i << "j = "<<j <<endl;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin>>a[i][j];
    spiral(n,m);
}
