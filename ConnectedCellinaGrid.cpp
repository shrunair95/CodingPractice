#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int calc(vector< vector<int> > &grid,int i,int j){
    int c;
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
        return 0;
    if(grid[i][j]==0)
        return 0;
    c=grid[i][j]--;
    c+=calc(grid,i-1,j);
    c+=calc(grid,i+1,j);
    c+=calc(grid,i,j-1);
    c+=calc(grid,i,j+1);
    c+=calc(grid,i-1,j-1);
    c+=calc(grid,i-1,j+1);
    c+=calc(grid,i+1,j-1);
    c+=calc(grid,i+1,j+1);
    return c;
    
}

int get_biggest_region(vector< vector<int> > grid) {
    int max=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            int temp=calc(grid,i,j);
            if(temp>max)
                max=temp;
        }
    }
    return max;
}


int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}

