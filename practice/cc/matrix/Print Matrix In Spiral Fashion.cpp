#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/matrices/MATRICES/problems/MATSPIRAL?tab=statement

// https://leetcode.com/problems/spiral-matrix/

void solve() {
    int n,m; cin>>n>>m;
    int mat[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>mat[i][j];
        }
    }
    
    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = m-1;
    
    int total_ele = n*m;
    int num_ele = 0;
    vector<int> ans;
    while(num_ele < total_ele) {
        // top
        for(int i=left; i<=right && num_ele<total_ele; i++) {
            ans.push_back(mat[top][i]);
            num_ele++;
        }
        top++;
        
        // right
        for(int i=top; i<=bottom && num_ele<total_ele; i++) {
            ans.push_back(mat[i][right]);
            num_ele++;
        }
        right--;
        
        // bottom
        for(int i=right; i>=left && num_ele<total_ele; i--) {
            ans.push_back(mat[bottom][i]);
            num_ele++;
        }
        bottom--;
        
        // left
        for(int i=bottom; i>=top && num_ele<total_ele; i--) {
            ans.push_back(mat[i][left]);
            num_ele++;
        }
        left++;
    }
    
    for(auto& it: ans) {
        cout<<it<<" ";
    }
    
    
    
    // int direction = 1;
    // while (left <= right && top <= bottom) {
    //   if (direction == 1) {
    //     for (int i = left; i <= right; i++) 
    //         cout << mat[top][i] << " ";
    //     direction = 2;
    //     top++;
    //   } else if (direction == 2) {
    //     for (int i = top; i <= bottom; i++) 
    //         cout << mat[i][right] << " ";
    //     direction = 3;
    //     right--;
    //   } else if (direction == 3) {
    //     for (int i = right; i >= left; i--) 
    //         cout << mat[bottom][i] << " ";
    //     direction = 4;
    //     bottom--;
    //   } else if (direction == 4) {
    //     for (int i = bottom; i >= top; i--) 
    //         cout << mat[i][left] << " ";
    //     direction = 1;
    //     left++;
    //   }
    // }
}

int main() {
    solve();
    return 0;
}