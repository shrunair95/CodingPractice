#include <bits/stdc++.h>

using namespace std;

void countingSort(vector <int> arr) {
    // Complete this function
    int output[arr.size()];
    int count[100]={0};
    for(int i=0;i<arr.size();i++)
        ++count[arr[i]];
    for(int i=1;i<100;i++)
        count[i]+=count[i-1];
    for(int i=0;i<arr.size();i++){
        output[count[arr[i]]-1]=arr[i];
        --count[arr[i]];
    }
    for(int i=0;i<arr.size();i++){
        cout<<output[i]<<" ";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    countingSort(arr);
    
    cout << endl;


    return 0;
}

