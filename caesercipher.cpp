#include <bits/stdc++.h>

using namespace std;

void caesarCipher(string s, int k) {
    // Complete this function
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i])){
            char a = isupper(s[i])?'A':'a';
            s[i]= a + (s[i] - a + k)%26;
        }
       
    }
    cout<<s;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    caesarCipher(s, k);
    return 0;
}