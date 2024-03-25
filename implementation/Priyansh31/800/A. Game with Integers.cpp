#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>

void solve() {
    int t; cin>>t;
    while(t--) {
       int n; cin>>n;
       
       if(n%3 == 0) {
           cout<<"Second\n";
       } else {
           cout<<"First\n";
       }
    }
}


int main() {
	solve();
	return 0;
}