#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/basic-math/BASICMATH/problems/FLOW006?tab=Submissions

void solve() {
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        int sum = 0;
        for(auto& it: s) {
            sum += (it - '0');
        }
        cout<<sum<<endl;   
    }
}

int main() {
    solve();
    return 0;
}