#include<bits/stdc++.h>
#define M 4
#define N 4
using namespace std;

int grid [M][N] = {{1,0,1,1},
                  {0,1,1,0},
                  {0,0,1,1},
                  {1,0,0,0}};

int connected_grid(bool visited[M][N],int i, int j, int &count, int &max){
  if(grid[i][j]==1){
    count++;
    visited[i][j]=true;
    for(int l = i-1;l<=i+1;l++){
      for(int k = j-1;k<=j+1;k++){
        if(visited[l][k]==false && l>=0 && k>=0 && l<M && k<N){
          connected_grid(visited,l,k,count,max);
        }
      }
    }
    if(max<count)
      max = count;
    count = 0;
    visited[i][j]=false;
  }
}


int main(){
  bool visited[M][N]={{false}};
  int max = -1;
  int count=0;
  for(int i =0;i<M;i++){
    for(int j = 0;j<N;j++){
      connected_grid(visited, i, j,count,max);
    }
  }
  cout<<max;
}
  
