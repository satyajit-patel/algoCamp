#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>

void solve() {
    int t; cin>>t;
    while(t--) {
       int n,k; cin>>n>>k;
       int arr[n];
       for(int i=0; i<n; i++) {
           cin>>arr[i];
       }
       
       if(k == 1) {
           if(is_sorted(arr, arr+n)) {
               cout<<"YES\n";
           } else {
               cout<<"NO\n";
           }
       } else {
           cout<<"YES\n";
       }
    }
}


int main() {
	solve();
	return 0;
}