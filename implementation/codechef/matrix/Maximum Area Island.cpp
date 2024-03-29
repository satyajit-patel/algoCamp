#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

// https://www.codechef.com/practice/course/matrices/MATRICES/problems/MATMAXISLAND

/*
    input   output
    3 3     6
    0 1 1
    0 1 1
    0 1 1
*/

// up right down left1
int dx[4] = {-1, 0, +1, 0};
int dy[4] = {0, +1, 0, -1};

int bfs(int i, int j, vvi& mat) {
    mat[i][j] = 0;
    int size = 0;
    
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        
        size++;
        for(int ind=0; ind<4; ind++) {
            int ni = i + dx[ind];
            int nj = j + dy[ind];
            if(ni<mat.size() && ni>=0 && nj<mat[0].size() && nj>=0) {
                if(mat[ni][nj] == 1) {
                    mat[ni][nj] = 0;
                    q.push({ni, nj});    
                }
            }
        }
    }
    
    // for(auto& row: mat) {
    //     for(auto& it: row) {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
    
    return size;
}

void solve() {
    int n,m; cin>>n>>m;
    vvi mat(n, vi(m));
    for(auto& row: mat) {
        for(auto& it: row) {
            cin>>it;
        }
    }
    
    int ans = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 1) {
                ans = max(ans, bfs(i, j, mat));
            } 
        }
    }
    
    cout<<ans;
}

int main() {
    solve();
    return 0;
}