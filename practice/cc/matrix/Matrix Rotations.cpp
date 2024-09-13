#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/matrices/MATRICES/problems/MATROTATE

void solve() {
    int n; cin>>n;
    vector<vector<int>> mat(n, vector<int>(n));
    for(auto& row: mat) {
        for(auto& it: row) {
            cin>>it;
        }
    }
    
    vector<vector<int>> ans(n, vector<int>(n));
    int ind = n-1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans[j][ind] = mat[i][j];
        }
        ind--;
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