#include<iostream>
#include<list>
using namespace std;

class graph{
	int V;
	list<int> *adj;
	bool cycle_detect_util(int v,bool visited[], int parent);
	public:
		graph(int V);
		void add_edge(int a,int b);
		bool cycle_detect();
};

graph::graph(int V){
	this->V=V;
	adj=new list<int>[V];
}

void graph::add_edge(int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

bool graph::cycle_detect(){
	bool *visited= new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	for(int i=0;i<V;i++){
		if(visited[i]==false){
			if(cycle_detect_util(i,visited,-1))
				return true;
		}
	}
	return false;
}

bool graph::cycle_detect_util(int v,bool visited[], int parent){
	visited[v]=true;
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++){
		if(visited[*i]==false){
			if(cycle_detect_util(*i,visited,v))
				return true;
		}
		else if(parent!=*i)	
			return true;	
	}
	return false;
}

int main(){
	graph g1(5);
    g1.add_edge(1, 0);
    g1.add_edge(0, 2);
    g1.add_edge(2, 0);
    g1.add_edge(0, 3);
    g1.add_edge(3, 4);
    if(g1.cycle_detect())
    	cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";
        
    graph g2(3);
    g2.add_edge(0, 1);
    g2.add_edge(1, 2);
    if(g2.cycle_detect())
    	cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";
 
 
    return 0;


}
