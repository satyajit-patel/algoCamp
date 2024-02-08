// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-140/problems
#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    vector<ll> dp;

    ll state(int n) {
        // base case
        if(n == 0) {
            return 2;
        }
        if(n == 1) {
            return 5;
        }
        if(n == 2) {
            return 9;
        }
        if(n == 3) {
            return 7;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        
        // transition
        if(n%2) {
            return dp[n] = ((state(n-1)*(n-1)) + (state(n-3)*(n-3))) % mod;
        } else {
            return dp[n] = ((state(n-2)*(n-2)) + (state(n-4)*(n-4))) % mod;
        }
    }
    
    int findFun(int n) {
        dp.resize(n+1, -1);
        ll ans = state(n);
        return ans;
    }
};