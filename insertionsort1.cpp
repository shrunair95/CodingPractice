#include <bits/stdc++.h>

using namespace std;

void insertionSort1(int n, vector <int> arr) {
    // Complete this function
    int e=arr[n-1];
    int j;
    for(int i=0;i<n-1;i++){
        j=n-2;
        while(j>=0 && arr[j]>e){
            arr[j+1]=arr[j];
            j--;
            for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
        arr[j+1]=e;
        break;
    }
    for(int i=0;i<n;i++)
          cout<<arr[i]<<" ";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    insertionSort1(n, arr);
    return 0;
}

