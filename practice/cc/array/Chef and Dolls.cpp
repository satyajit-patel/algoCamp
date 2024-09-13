#include<bits/stdc++.h>
using namespace std;

https://www.codechef.com/practice/course/arrays-strings-sorting/INTARR01/problems/MISSP

int f(int* arr, int n) {
    map<int, int> mp;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }
    for(auto& it: mp) {
        if(it.second%2) {
            return it.first;
        }
    }
    return -1;
}

void solve() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        
        cout<<f(arr, n)<<endl;
        
    }
}

int main() {
    solve();
    return 0;
}