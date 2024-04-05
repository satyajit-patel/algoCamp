#include<bits/stdc++.h>
using namespace std;

/*
https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14004

    1 ≤ N ≤ 2×10^5
    
    input           output
    5               23
    10 3 5 7 3 
*/

int state(int i, int count, int n, auto& A, auto& dp) {
    // base case
    if(i >= n) {
        return 0;
    }
    if(dp[i][count] != -1) {
        return dp[i][count];
    }
    
    // transition
    int take = 0;
    if(count < 3) {
        take = A[i] + state(i+1, count+1, n, A, dp);    
    }
    int notTake = state(i+1, 1, n, A, dp);
    int ans = max(take, notTake);
    dp[i][count] = ans;
    return ans;
}

void solve() {
    int n; cin>>n;
    vector<int> A(n);
    for(auto& it: A) {
        cin>>it;
    }
    
    vector<vector<int>> dp(n+1, vector<int>(3+1, -1));
    int ans = state(0, 1, n, A, dp);
    cout<<ans;
}

int main() {
    solve();
    return 0;
}