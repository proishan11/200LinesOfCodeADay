/*CPLAY*/

#include<bits/stdc++.h>

using namespace std;
int result[3];
int main(){

	string a;
	while(1){
		int chef_count=0, op_count=0, c1=5, c2=5;
		result[1]=0;
		result[0]=0;
		result[2]=0;
		bool x=false;
		getline(cin,a);
		if(a.length()!=0){
			for(int i=0; i<10; ++i){
				if(i%2==0){
					c1--;
					if(a[i]=='1')
						chef_count++;
				}
				if(i%2!=0){
					c2--;
					if(a[i]=='1')
						op_count++;
				}
				
				if(op_count+c2<chef_count && x==false){
					result[0]=1;
					result[2]=i+1;
					x=true;
				}
				if(chef_count+c1<op_count && x==false){
					result[1]=1;
					result[2]=i+1;
					x=true;
				}
			}

			if(x==false){
				for(int i=10; i<20; i+=2){
					
					if(a[i]=='1' && a[i+1]=='0' &&x==false){
						result[0]=1;
						result[2]=i+2;
						x=true;
					}
					if(a[i]=='0' && a[i+1]=='1' && x==false){
						result[1]=1;
						result[2]=i+2;
						x=true;
					}
				}
			}
			if(result[0]==1){cout<<"TEAM-A "<<result[2]<<endl;}
			if(result[1]==1){cout<<"TEAM-B "<<result[2] <<endl;}
			if(result[0]==0 && result[1]==0){cout<<"TIE"<<endl;}
			
		}
		
		else break;
	}
}