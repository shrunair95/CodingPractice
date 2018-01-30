#include<iostream>
#include<list>
using namespace std;

class graph{
	int V;
	list<int> *adj;
	bool cycle_detect_util(int v,bool visited[], bool recstack[]);
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
}

bool graph::cycle_detect(){
	bool *visited= new bool[V];
	bool *recstack=new bool[V];
	for(int i=0;i<V;i++){
		visited[i]=false;
		recstack[i]=false;
	}
	for(int i=0;i<V;i++){
		if(cycle_detect_util(i,visited,recstack))
			return true;	
	}
	return false;
}

bool graph::cycle_detect_util(int v,bool visited[], bool recstack[]){
	if(visited[v]==false){
		visited[v]=true;
		recstack[v]=true;
		list<int>::iterator i;
		for(i=adj[v].begin();i!=adj[v].end();i++){
			if(visited[*i]==false){
				if(cycle_detect_util(*i,visited,recstack))
					return true;
			}
			else if(recstack[*i]==true)	
				return true;	
		}
	}
	recstack[v]=false;
	return false;
}

int main(){
	graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    if(g.cycle_detect())
    	cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";
 
 
    return 0;


}
