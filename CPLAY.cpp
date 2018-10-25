#include<bits/stdc++.h>

using namespace std;
int result[2];
int main(){

	string a;
	while(1){
		int chef_count=0, op_count=0, rem_count=10;
		bool x=false;
		getline(cin,a);
		if(a.length()!=0){

			for(int i=0; i<10; ++i){
				if(i%2==0){
					if(a[i]=='1')
						chef_count++;
					
				}
				if(i%2!=0){
					if(a[i]=='1')
						op_count++;
				}
				rem_count--;
				//cout<<"chef- "<<chef_count<<endl;
				//cout<<"opp- "<<op_count<<endl;
				//cout<<"rem_count " <<rem_count<<endl;
				if(chef_count-op_count>rem_count && x==false){
					//cout<<"reached1"<<endl;
					result[0]=1;
					result[2]=i+1;
					x=true;
				}
				if(op_count-chef_count>rem_count && x==false){
					//cout<<"reached2"<<endl;
					result[1]=1;
					result[2]=i+1;
					x=true;
				}
			}


			if(x==false){
				for(int i=10; i<20; i+=2){
					//cout<<a[i]<<" ";
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

			
		
			if(x==false){result[2]=20;}
			
			if(result[0]==1){cout<<"CHEF"<<endl;}
			if(result[1]==1){cout<<"CHEF_OPP"<<endl;}
			if(result[0]==0 && result[1]==0){cout<<"TIE"<<endl;}
			cout<<"Total Matches"<<result[2]<<endl;
		}
		
		else break;
	}
}