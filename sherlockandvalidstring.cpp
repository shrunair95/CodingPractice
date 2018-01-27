#include <bits/stdc++.h>

using namespace std;

string isValid(string s){
    // Complete this function
    int count[26]={0};
    int flag=0;
    int ref;
    int max=-1;
    for(int i=0;i<s.length();i++){
        count[s[i]-'a']++;
        
    }
    for(int i=0;i<26;i++){
       
        if(count[i]>0){
            ref=count[i];
            break;
        }
        
    }
    for(int i=0;i<26;i++){
        if(count[i]>0){
            if(ref!=count[i] && flag==0 && abs(count[i]-ref)==1){ //changed 1 digit
                flag=1;
                continue;
            }
            else if(((ref!=count[i] && flag==1) || abs(count[i]-ref)>1)){
                if(count[i]==1 && flag==0)
                    continue;
                return "NO";
        }
        }
    }
    return "YES";
        
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}

