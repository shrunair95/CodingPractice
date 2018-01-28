#include <bits/stdc++.h>

using namespace std;
int opt[10000][10000];

int commonChild(string s1, string s2){
    // Complete this function
    for(int i=0;i<=s1.length();i++){
        for(int j=0;j<=s2.length();j++){
            if(i==0 || j== 0)
                opt[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                opt[i][j]=opt[i-1][j-1] + 1;
            else
                opt[i][j]=max(opt[i-1][j],opt[i][j-1]);
        }
    }
    return (opt[s1.length()][s2.length()]);
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = commonChild(s1, s2);
    cout << result << endl;
    return 0;
}