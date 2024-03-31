#include<bits/stdc++.h>
using namespace std;

/*
    input   
    3 3     
    0 1 1
    0 1 0
    1 1 1
    
    output
    0 1 1
    0 1 0
    1 2 1
    
    1 <= n, m <= 100
    
    f(n) = O(n^4)
*/

int dx[4] = {-1, 0, +1, 0}; // URDL
int dy[4] = {0, +1, 0, -1};

// https://www.codechef.com/practice/course/matrices/MATRICES/problems/MATNEARESTO

vector<vector<int>> multi_bfs(auto& q, auto& mat, auto& vis) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 0));
    while(!q.empty()) {
        int steps = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();
        
        dist[i][j] = steps;
        
        for(int ind=0; ind<4; ind++) {
            int ni = i + dx[ind];
            int nj = j + dy[ind];
            if(ni>=0 && ni<n && nj>=0 && nj<m) {
                if(!vis[ni][nj]) {
                    vis[ni][nj] = 1;
                    q.push({steps+1, {ni, nj}});
                }
                
            }
        }
    }
    return dist;
}

// int bfs(auto& mat, int i, int j) {
//     int n = mat.size();
//     int m = mat[0].size();
//     vector<vector<int>> vis(n, vector<int>(m, 0));
//     vis[i][j] = 1;
//     queue<pair<int, pair<int, int>>> q;
//     q.push({0, {i, j}});
//     while(!q.empty()) {
//         int curDist = q.front().first;
//         i = q.front().second.first;
//         j = q.front().second.second;
//         q.pop();
        
//         if(mat[i][j] == 0) {
//             return curDist;
//         }
        
//         for(int ind=0; ind<4; ind++) {
//             int ni = i + dx[ind];
//             int nj = j + dy[ind];
//             if(ni>=0 && ni<n && nj>=0 && nj<m) {
//                 if(!vis[ni][nj]) {
//                     vis[ni][nj] = 1;
//                     q.push({curDist+1, {ni, nj}});
//                 }
//             }
//         }
//     }
//     return -1;
// }

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(auto& row: mat) {
        for(auto& it: row) {
            cin>>it;
        }
    }
    
    
    // // brute force
    // // (n*m) * bfs(n*m) = O(n^4) 
    // vector<vector<int>> ans = mat;
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         if(mat[i][j] == 1) {
    //             ans[i][j] = bfs(mat, i, j); 
    //         }
    //     }
    // }
    
    // optimal
    // (n*m) + (n*m) = O(n^2)
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // O(n^2)
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 0) {
                q.push({0, {i, j}});
                vis[i][j] = 1;
            }
        }
    }
    // O(n^2)
    vector<vector<int>> ans = multi_bfs(q, mat, vis);
    
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}