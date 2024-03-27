#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/matrices/MATRICES/problems/MATZIGZAG

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(auto& row: mat) {
        for(auto& it: row) {
            cin>>it;
        }
    }
    
    bool forword = true;
    for(int i=0; i<n; i++) {
        if(forword) {
            for(int j=0; j<m; j++) {
                cout<<mat[i][j]<<" ";
            }
            forword = false;
        } else {
            for(int j=m-1; j>=0; j--) {
                cout<<mat[i][j]<<" ";
            }
            forword = true;
        }
    }
}

int main() {
    solve();
    return 0;
}