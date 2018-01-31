#include<iostream>
using namespace std;

#define V 9
int cost[V][V]={{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
int dist[V];
int visited[V];

int get_min(){
	int min=INT_MAX;
	int min_vertex;
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false && min>=dist[i]){
			min=dist[i];
			min_vertex=i;
		}
	}	
	return min_vertex;
}

void djikstras(int s){
	dist[s]=0;
	for(int c=0;c<V-1;c++){
	int v=get_min();
	visited[v]=true;
	for(int i=0;i<V;i++)
	{
		if(cost[v][i]!=0 && visited[i]==false){
			if(dist[i]>cost[v][i]+dist[v])
				dist[i]=cost[v][i]+dist[v];
		}
	}
	}
	for(int i=0;i<V;i++)
		cout<<dist[i]<<" ";
}


int main()
{
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX;
		visited[i]=false;
	}
	djikstras(0);
}