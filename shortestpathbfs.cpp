#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
    Graph(int V);
    void add_edge(int a,int b);
    void BFS(int V);
};

Graph::Graph(int V){
    this->V=V;
    adj=new list<int>[V+1];
}

void Graph::add_edge(int a, int b){
    adj[a].push_back(b);   
    adj[b].push_back(a); 
}

void Graph::BFS(int s){
    int dist[V+1];
    bool *visited=new bool[V+1];
    for(int i=0;i<=V;i++){
        dist[i]=0;
        visited[i]=false;
    }
    list<int>queue;
    visited[s]=true;
    queue.push_back(s);
    
    list<int>::iterator i;
    while(!queue.empty()){
        int t=queue.front();
        queue.pop_front();
        for(i=adj[t].begin();i!=adj[t].end();i++){
            if(!visited[*i]){
                visited[*i]=true;
                dist[*i]+=(dist[t]+6);
                queue.push_back(*i);
            }
        }
    }
    for(int i = 1; i <= V; i++) {
        if(i != s) {
                if(dist[i] == 0) {
                    cout<<"-1 ";
                } else {
                    cout<<dist[i]<<" ";
                }
            }
        }
 cout<<endl;
}

int main()
{
    int q,n,m,a,b,s;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>n>>m;
        Graph g(n);
        for(int j=0;j<m;j++)
        {
            cin>>a>>b;
            g.add_edge(a,b);
        }
        cin>>s;
        g.BFS(s);
    }
}