#include <bits/stdc++.h>

using namespace std;

int anagram(string s){
    // Complete this function
    int sum=0;
    int len=s.length();
    int count[26]={0};
    if(len%2!=0)
        return -1;
    for(int i=0;i<(len/2);i++)
        count[s[i]-'a']++;
    for(int i=(len/2);i<len;i++)
        count[s[i]-'a']--;
    for(int i=0;i<26;i++)
        if(count[i]>0)
            sum+=count[i];
    return sum;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = anagram(s);
        cout << result << endl;
    }
    return 0;
}