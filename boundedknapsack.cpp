#include<iostream>
using namespace std;

int weight[]={1,3,4,5};
int value[]={1,4,5,7};
int total_wt=7;
int opt[4][8];

void knapsack(){
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			if(j==0)
				opt[i][j]=0;
			else if(i==0){
				if(weight[i]>j)
					opt[i][j]=0;
				else
					opt[i][j]=value[i];
			}
			else if(j<weight[i])
				opt[i][j]=opt[i-1][j];
			else
				opt[i][j]=max(opt[i-1][j],value[i]+opt[i-1][j-weight[i]]);
		}
	}
	cout<<"MAX VALUE: "<<opt[3][7];
	int i=3,j=7;
	while(i!=0 && j!=0){
		if(opt[i][j]==opt[i-1][j])
			i--;
		else{
			cout<<endl<<"Item with weight "<<weight[i]<<" and value "<<value[i]<<" chosen.";
			j-=weight[i--];
		}
	}
}

int main()
{
	knapsack();
}