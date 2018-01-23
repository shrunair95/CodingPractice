#include<iostream>
#include<list>
using namespace std;

class graph{
		int V;
		list<int> *adj;
		void DFSutil(int v,bool *visited);
	public:
		graph(int V);
		void add_edge(int a,int b);
		void DFS(int a);
	
};

graph::graph(int V){
	this->V=V;
	adj=new list<int>[V];
}

void graph::add_edge(int a,int b){
	adj[a].push_back(b);
}

void graph::DFS(int a){
	bool *visited=new bool[V];
	for(int i=0;i<V;i++){
		visited[i]=false;
	}
	DFSutil(a,visited);
}

void graph::DFSutil(int v,bool *visited){
	visited[v]=true;
	cout<<v<<" ";
	list<int> ::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++){
		if(visited[*i]==false)
			DFSutil(*i,visited);
	}
}

int main(){
	graph g(6);
	g.add_edge(0,1);
	g.add_edge(0,5);
	g.add_edge(0,4);
	g.add_edge(1,4);
	g.add_edge(1,3);
	g.add_edge(3,2);
	g.add_edge(3,4);
	g.add_edge(2,1);
	g.DFS(0);
}