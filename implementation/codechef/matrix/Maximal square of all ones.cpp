#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

/*
https://www.codechef.com/practice/course/matrices/MATRICES/problems/MATMAXSQ?tab=statement

    input   output
    3       4
    0 1 0
    0 1 1
    0 1 1
*/

vvi mat;
int maxArea;

int state(int i, int j) {
    // base case
    if(i >= mat.size()) {
        return 0;
    }
    if(j >= mat[0].size()) {
        return 0;
    }
    
    // transition
    int right = state(i, j+1);
    int diagonal = state(i+1, j+1);
    int down = state(i+1, j);
    int ans = 0;
    if(mat[i][j] == 1) {
        ans = 1 + min({right, diagonal, down});
        maxArea = max(maxArea, ans);
    }
    return ans;
}

void solve() {
    int n; cin>>n;
    mat.clear(), mat.resize(n, vi(n));
    for(auto& row: mat) {
        for(auto& it: row) {
            cin>>it;
        }
    }
    
    maxArea = 0;
    int ans = state(0, 0);
    cout<< maxArea * maxArea;
}

int main() {
    solve();
    return 0;
}