#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler008/problem?isFullScreen=true

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    int nums[n];
    for(int i=0; i<n; i++) {
        nums[i] = s[i] - '0';
    }
    
    int prod = 1;
    int zeroCount = 0;
    for(int i=0; i<k; i++) {
        // cout << nums[i] << endl;
        if(nums[i] == 0) {
            zeroCount++;
        } else {
            prod *= nums[i];
        }
    }
    int init = 0;
    int ans = 0;
    if(zeroCount == 0) {
        ans = prod;
    }
    // cout << prod << " -> ";
    for(int i=k; i<n; i++) {
        if(nums[i] == 0) {
            zeroCount++;
        } else {
            prod *= nums[i];
        }
        if(nums[init] != 0) {
            prod /= nums[init++];
        } else {
            init++;
            zeroCount--;
        }
        if(zeroCount == 0) {
            ans = max(ans, prod);
        }
        // cout << prod << " -> ";
    }
    cout << ans << endl; 
}

signed main() {
//  solve();
int t; cin >> t;
while(t--) {
    solve();
}
  return 0;
}
