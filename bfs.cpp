#include<iostream>
#include<queue>
#include<string>
#include<map>
#include<iterator>

using namespace std;

bool findElement(queue<string> q, string elem){
	string temp;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp == elem){return true;}
	}
	return false;
}

int getMin(string from, string to){
	
	map< string, int > level,parent;
	string temp,temp2;
	parent[from] = 1;
	level[from] = 0;
	//cout<<level[from];
	int l=1,length;
	queue<string> frontier,next;
	frontier.push(from);
	cout<<findElement(frontier,from)<<endl;
	//temp.push(to);
	//frontier = temp;

	//cout<<frontier.front()<<endl;
	while(!frontier.empty()){
		while(!next.empty())
			next.pop();
		for(int i=0; i<frontier.size(); ++i){
			temp=frontier.front();
			length = temp.length();
			//cout<<temp.length()<<endl;
			//cout<<length<<endl;
			
			for(int x=0; x<length; ++x)
				for(int y=x+1; y<length; ++y){
					temp2 = temp;
					swap(temp2[x],temp2[y]);
					//cout<<temp2<<endl;
					
					if(!findElement(frontier,temp2) && !(parent.count(temp2)>0)){
						parent[temp2] = i;
						level[temp2] = l;
						next.push(temp2);	
					}
					//if(temp2.compare(to) == 0){return level[temp2];}
				}
			frontier=next;
		}
		l++;
	}
	return level[to];
}

int main(){

	string from="apple", to="elppa";
	cout<<  getMin(from, to) << endl;
}