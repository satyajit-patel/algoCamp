#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/heaps/HEAPF/problems/HEAPEDU3

void solve() {
    int t; cin>>t;
    priority_queue<int> pq;
    while(t--) {
        char ch; cin>>ch;
        
        if(ch == '+') {
            int n; cin>>n;
            pq.push(n);    
        } else {
            pq.pop();
        }
        cout<<pq.top()<<endl;
    }
}

int main() {
    solve();
    return 0;
}