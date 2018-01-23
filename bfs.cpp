#include<iostream>
#include<list>
using namespace std;

class graph{
		int V;
		list<int> *adj;
	public:
		graph(int v);
		void add_edge(int a,int b);
		void bfs(int a);
};

graph::graph(int v){
	this->V=v;
	adj= new list<int>[v];
}

void graph::add_edge(int a,int b){
	adj[a].push_back(b);
}

void graph::bfs(int a){
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	list<int> q;
	q.push_back(a);
	visited[a]=true;
	
	while(!q.empty()){
		int a=q.front();
		q.pop_front();
		cout<<a<<" ";
		list<int>::iterator	i;
		for(i=adj[a].begin();i!=adj[a].end();i++){
			if(visited[*i]==false){
				visited[*i]=true;
				q.push_back(*i);
			}
		}
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
	g.bfs(0);
}