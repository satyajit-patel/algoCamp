#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/matrices/MATRICES/problems/MATROTAPPLE

/*
    input       output
    3 4         4
    0 2 1 1  
    1 1 0 1 
    1 1 0 1
*/

int dx[4] = {-1, 0, +1, 0}; // URDL
int dy[4] = {0, +1, 0, -1};

void solve() {
    // input
    int n,m; cin>>n>>m;
    int mat[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>mat[i][j];
        }
    }
    
    // logic
    int empty_cell = 0;
    int fresh_apple = 1;
    int rotten_apple = 2;
    
    int total_apple = 0;
    int max_time = INT_MIN;
    queue<pair<int, pair<int, int>>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] != empty_cell) {
                total_apple++;
                if(mat[i][j] == rotten_apple) {
                    q.push({0, {i, j}});
                }
            }
        }
    }
    
    int num_rotten_apple = 0;
    while(!q.empty()) {
        int cur_time = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();
        
        // cout<<cur_time<<endl;
        num_rotten_apple++;
        max_time = max(max_time, cur_time);
        
        for(int ind=0; ind<4; ind++) {
            int ni = i + dx[ind];
            int nj = j + dy[ind];
            if(ni>=0 && ni<n && nj>=0 && nj<m) {
                if(mat[ni][nj] == fresh_apple) {
                    mat[ni][nj] = rotten_apple;
                    q.push({cur_time+1, {ni, nj}});
                }
            }
        }
    }
    
    // cout<<num_rotten_apple<<" "<<total_apple<<endl;
    if(num_rotten_apple == total_apple) {
        cout<<max_time;
    } else {
        cout<<-1;
    }
}

int main() {
    solve();
    return 0;
}