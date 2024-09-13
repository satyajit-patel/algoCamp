#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/matrices/MATRICES/problems/MATMEDIAN?tab=statement

void solve() {
    int n,m; cin>>n>>m;
    // int mat[n][m];
    vector<vector<int>> mat(n, vector<int>(m));
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cin>>mat[i][j];
    //     }
    // }
    for(auto& row: mat) {
        for(auto& it: row) {
            cin>>it;
        }
    }
    // 3 4 5 2 4 6 4 6 7
    // 2 3 4 4 4 5 6 6 7
    
    vector<int> arr;
    for(auto& row: mat) {
        for(auto& it: row) {
            arr.push_back(it);
        }
    }
    
    sort(arr.begin(), arr.end());
    cout<<arr[arr.size()/2];
}

int main() {
    solve();
    return 0;
}