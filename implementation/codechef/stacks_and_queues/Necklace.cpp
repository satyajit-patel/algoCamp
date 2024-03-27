#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/stacks-and-queues/STAQUEF/problems/NEC

void solve() {
    int t; cin>>t;
    while(t--) {
        int n,k; cin>>n>>k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        
        queue<int> q;
        for(auto& it: arr) {
            q.push(it);
        }
        while(k--) {
            int num = q.front();
            q.pop();
            q.push(num);
        }
        while(!q.empty()) {
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}