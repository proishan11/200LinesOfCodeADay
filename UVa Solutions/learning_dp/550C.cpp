#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

string result;

map< string, bool > dp;

bool divisible(string s){
    int n = s.length();
    if(n==0) return true;
    string last3;
    if(n>=3)
        last3 = s.substr(n-3,n);
    else
        last3 = s;
    if(stoi(last3)%8 == 0)
        return true;
    else
        return false;
}

bool isdivisible(string sofar, string rest){
    if(rest==""){
        if(sofar.length()>0){
            if(dp.find(sofar) == dp.end()){
                if(divisible(sofar)){
                    dp[sofar] = true;
                    return true;
                }
                else{
                     dp[sofar] = false;
                     return false;
                }
            }
            else{
                return dp[sofar];
            }
        }
        else return false;

        /*if(divisible(sofar) && sofar.length()>0){
            result = sofar;
            return true;
        }
        else return false;*/
    }
    if(isdivisible(sofar+rest[0], rest.substr(1))){

        return true;
    }
    if(isdivisible(sofar, rest.substr(1))){

        return true;
    }
    return false;
}

int main(){
    string num;
    cin>>num;
    if(isdivisible("", num))
        cout<<"YES\n"<<result<<endl;
    else
        cout<<"NO\n";
}
