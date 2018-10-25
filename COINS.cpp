#include<bits/stdc++.h>

using namespace std;

map<int, long> store;

long compute(int n){
	if(store.find(n) != store.end())
		return store[n];
	long temp;
	if(n<=2)
		temp=n;
	else
		temp = compute(n/2)+compute(n/3)+compute(n/4);
	if(temp<n)
		temp=n;
	store[n]=temp;
	return temp;
}

int main(){
	int n;
	while(scanf("%d",&n) == 1){
		printf("%ld\n", compute(n));
	}
}