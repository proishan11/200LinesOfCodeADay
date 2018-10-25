#include<bits/stdc++.h>

using namespace std;

void printInBinary(int n){
    if(n==0 || n==1)
        cout<<n;

        //Look at the placement of recursive function
        //It will first print 1's place as recursively n/2
    else{
        printInBinary(n/2);
        cout<<n%2;
    }
}

int main(){
    int n;
    cin>>n;
    printInBinary(n);
    cout<<endl;
}
