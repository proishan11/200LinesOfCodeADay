#include<bits/stdc++.h>
using namespace std;


int n, k;

vector<int> a;
vector<int> solution, best_solution;

int check_sum(vector<int> solution){
	int sum = 0;
	for(int i=0; i<solution.size(); ++i){
		if(solution[i]>0)
			sum += solution[i];
	}
	return sum;
}

bool can_push(int index, vector<int> solution){
	return check_sum(solution)+a[index] < n;
}


void print_solution(vector<int> solution){
	for(int i=0; i<solution.size(); ++i)
		cout<<solution[i]<<" ";
	cout<<endl;
}

bool solve(int label, vector<int> solution, int current_max){
	cout<<"sum = "<< check_sum(solution)<<endl;
	if(check_sum(solution)>n)
		return false;

	if(check_sum(solution) > current_max){
		//cout<<"here\n";
		current_max = check_sum(solution);
		best_solution = solution;
		if(current_max == n)
			return true;
	}

	cout << "sol =  ";
	print_solution(solution);
	for(int i=label; i<a.size(); ++i){
		if(can_push(i, solution)){
			solution.push_back(a[i]);
			if(solve(label+1, solution, current_max))
				return true;
			cout<<"he2\n";
			cout << "s1 =  ";
			print_solution(solution);
			solution.erase(solution.begin()+solution.size()-1);
			cout << "s2 =  ";
			print_solution(solution);
		}
	}

	return false;
}





int main(){
	int temp;
	cin>>n>>k;
	
	for(int i=0; i<k; ++i){
		cin>>temp;
		a.push_back(temp);
	}

	solve(0, solution, 0);

	print_solution(best_solution);

}	