#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/matrices/MATRICES/problems/MATSETZERO

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(auto& row: mat) {
        for(auto& it: row) {
            cin>>it;
        }
    }
    
    vector<vector<int>> ans = mat;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 0) {
                // setting row to zero
                for(int k=0; k<m; k++) {
                    ans[i][k] = 0;
                }
                // setting column to zero
                for(int k=0; k<n; k++) {
                    ans[k][j] = 0;
                }
            }
        }
    }
    for(auto& row: ans) {
        for(auto& it: row) {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}