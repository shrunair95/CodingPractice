#include<iostream>
using namespace std;

string dictionary[]={"GEEKS","FOR","QUIZ","GO"};
int n=sizeof(dictionary)/sizeof(dictionary[0]);

int isWord(string &str){
	for(int i=0;i<n;i++){
		if(str.compare(dictionary[i])==0)
			return true;
	}
	return false;
}

void findwordsutil(char boggle[3][3],bool visited[3][3],int i,int j,string &str){
	visited[i][j]=true;
	str+=boggle[i][j];
	if(isWord(str))
		cout<<str<<endl;
	for(int r=i-1;r<=i+1 && r<3;r++)
	{
		for(int c=j-1;c<=j+1 && c<3;c++)
		{
			if(visited[r][c]==false && r>=0 && c>=0)
				findwordsutil(boggle,visited,r,c,str);
		}
	}
	str.erase(str.length()-1);
	visited[i][j]=false;
}

void findwords(char boggle[3][3])
{
	bool visited[3][3]={{false}};
	string str="";
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			findwordsutil(boggle,visited,i,j,str);
}

int main(){
	char boggle[3][3]={{'G','I','Z'},
					   {'U','E','K'},
					   {'Q','S','E'}};
	findwords(boggle);
	return 0;
}