#include <bits/stdc++.h>

using namespace std;

class graph{
    int V;
    long count;
    list<long>c;
    list<int>*adj;
    
    public:
    graph(int V){
        this->V=V;
        adj=new list<int> [V];
        count=0;
    }
    
    void addedge(int a,int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    void connectedcomponents(){
      
         bool* visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;
 
        for (int i=0; i<V; i++)
        {
            if (!visited[i]){
                count=0;
                DFS(i,visited);
                c.push_back(count);
                
            }
        }
        cout<<display();
        
    }
    
    int display()
    {
        
        long sum = 0,sum1;
        list<long>::iterator i;
        if(c.size()==1)
            return 0;
        for (i = c.begin(); i !=c.end() ; i++){
            sum = sum + *i;
            sum1 += (*i)*(*i);
        }
     
        return ((sum*sum) - sum1)/2;
    }
    
    void DFS(int i, bool visited[]){
        visited[i] = true;
        count++;
        list<int>::iterator j;
        for(j = adj[i].begin(); j != adj[i].end(); j++)
            if(!visited[*j])
                DFS(*j, visited);
        }
};


int main() {
    int n;
    int a;
    int b;
    int p;
    cin >> n >> p;
    graph g(n);
    for(int astronaut_i = 0;astronaut_i < p;astronaut_i++){
        cin>>a>>b;
       g.addedge(a,b);
    }
    g.connectedcomponents();
    return 0;
}