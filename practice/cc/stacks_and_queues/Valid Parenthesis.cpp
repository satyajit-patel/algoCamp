#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/stacks-and-queues/STAQUEF/problems/PREP59

bool f(string& s) {
    stack<char> st;
    for(auto& it: s) {
        if(it == '(') {
            st.push(it);
        } else {
            if(st.empty()) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

void solve() {
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        
        cout<<f(s)<<endl;
    }
}

int main() {
    solve();
    return 0;
}