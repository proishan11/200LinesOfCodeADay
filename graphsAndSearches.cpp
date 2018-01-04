#include <bits/stdc++.h>
using namespace std;
#define MAXV 100

class Graph{
	int nvertices=0, nedges=0, vertex1, vertex2;
	bool directed=false;
	vector<int> a[MAXV];
	int visited[MAXV];
	
	public:
	Graph(int a=0, int b=0, bool directed=false){
		if(!a && !b && !directed){
			cout<<"Enter number of vertices\n";
			cin >> nvertices;
			cout<<"Do You want this graph to be directed(Enter 1)\n";
			cin>>this->directed;
			cout<<"Enter number of Edges\n";
			cin>>nedges;
			cout<<"Enter the Edges\n";
			for(int i=0; i<nedges; ++i){
				cin>>vertex1>>vertex2;
				if(!addEdge(vertex1,vertex2))
					i--;
			}
		}
		else{
			nvertices = a;
			nedges = b;
			this->directed = directed;
		}
	}

	int addEdge(int vertex1, int vertex2){
		if(vertex1>nvertices || vertex2>nvertices){
			cout<<"Can't add vertex\n";
			return 0;
		}
		else{	
			a[vertex1].push_back(vertex2);
			cout<<"Edge added to vertex "<<vertex1<<"\n";
			if(directed){
				a[vertex2].push_back(vertex1);
				cout<<"Edge added to vertex "<<vertex2<<"\n";
			}
			return 1;
		}
	}

	void printGraph(){
		cout<<nvertices<<" :nvertices"<<endl;
		for(int i=1; i<=nvertices; ++i){
			if(a[i].size()){
				cout<<i<<": ";
				cout<<a[i][0];
				for(int j=1; j<a[i].size(); ++j)
					cout<<" -> "<<a[i][j];
				cout<<"\n";
			}
		}
	}

	void DFS(int source){
		memset(visited, 0, nvertices+1);
		procedureDFS(source);
		cout<<endl;
	}

	void procedureDFS(int source){
		//stack<int> S;
		visited[source] = 1;
		cout<<source<< " ";
		for(int i=0; i<a[source].size(); ++i){
			if(!visited[a[source][i]])
				procedureDFS(a[source][i]);
		}
	}
};

int main(){
	Graph graph;
	graph.DFS(2);
	//graph.printGraph();
}