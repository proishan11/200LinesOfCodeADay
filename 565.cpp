#include<bits/stdc++.h>
using namespace std;

int solution;
vector<int> gutthu;
int sum;

void get_solution(int current_sum, vector<int> array, vector<int> current){
    if(current_sum<=sum && current_sum>solution){
        solution = current_sum;
        gutthu = current;
    }

    vector<int> newArray;
    for(int j=1; j<array.size(); ++j)
        newArray.push_back(array[j]);

    for(int i=0; i<array.size(); ++i){
        vector<int> newVec = current;
        newVec.push_back(array[i]);
        get_solution(current_sum+array[i], newArray, newVec);
        get_solution(current_sum, newArray, current);
    }
}

int main(){
    int k;
    vector<int> a, current;
    int temp;
    cin>>sum>>k;
    for(int i=0; i<k; ++i){
        cin>>temp;
        a.push_back(temp);
    }

    get_solution(0, a, current);

    for(int i=0; i<gutthu.size(); ++i)
        cout<<gutthu[i]<<" ";
    cout<<endl;
}
