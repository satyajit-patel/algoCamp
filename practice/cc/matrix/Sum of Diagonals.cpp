#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/matrices/MATRICES/problems/MATDIAGSUM

void solve() {
    int n; cin>>n;
    int mat[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>mat[i][j];
        }
    }
    
    int sum = 0;
    int col = n-1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) {
                // cout<<mat[i][j]<<endl;
                sum += mat[i][j];
            }
            if(j == col) {
                sum += mat[i][j];
                col--;
            }
        }
    }
    if(n%2 == 1 && n > 1) {
        int ind = n/2;
        sum -= mat[ind][ind];
    }
    cout<<sum;
}

int main() {
    solve();
    return 0;
}