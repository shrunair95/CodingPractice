#include <bits/stdc++.h>

using namespace std;

class Graph{
    long long V;
    list<long long>c;
    list<long long>*adj;
    long long c_lib, c_road;
    long long sum;
    long long count;
    public:
    Graph(long long V,long long a,long long b){
        this->V=V;
        adj=new list<long long> [V+1];
        c_lib=a;
        c_road=b;
        sum=0;
        count=0;
    }
    
    void addedge(long long a,long long b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    void connectedcomponents(){
        bool* visited = new bool[V];
        list<long long>::iterator i;
        sum=0;
        for(long long i = 1; i <= V; i++)
            visited[i] = false;
        for (long long i=1; i<=V; i++)
        {   
            if (!visited[i])
            {
                count=0;
                DFS(i,visited);
                c.push_back(count);
                
            }
        }
        if(c_lib<=c_road)
            for(i=c.begin();i!=c.end();i++)
                sum+=c_lib * *i;
        else 
            for(i=c.begin();i!=c.end();i++)
                sum+=c_lib + ((*i - 1) *c_road);
        cout<<sum<<endl;
        c.clear();
    }
    
    void DFS(long long i, bool visited[])
    {
        visited[i] = true;
        count++;
        list<long long>::iterator j;
        for(j = adj[i].begin(); j != adj[i].end(); ++j)
            if(!visited[*j]){
                DFS(*j, visited);
            }
    }
};



int main() {
    int q,a,b;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        
        int c_lib;
        int c_road;
        
        cin >> n >> m >> c_lib >> c_road;
        Graph g(n,c_lib,c_road);
        for(int cities_i = 0;cities_i < m;cities_i++){
            cin>>a>>b;
            g.addedge(a,b);
        }
        g.connectedcomponents();
    }
    return 0;
}

