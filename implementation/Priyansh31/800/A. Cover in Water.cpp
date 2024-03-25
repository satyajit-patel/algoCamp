#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>

void solve() {
    int t; cin>>t;
    while(t--) {
       int n; cin>>n;
       string s; cin>>s;
       
       if(s.find("...") != -1) {
           cout<<"2\n";
       } else {
           map<char, int> map;
           for(auto& it: s) {
               map[it]++;
           }
           cout<<map['.']<<endl;
       }
    }
}


int main() {
	solve();
	return 0;
}