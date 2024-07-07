class Solution {
public:
    bool state(int i, vector<int>& nums, int n, vector<int>& dp) {
        // base case
        if(i == n-1) {
            return true;
        }
        if(i >= n) {
            return false;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        // transition
        bool ans = false;
        for(int j=1; j<=nums[i]; j++) {
            ans = state(i+j, nums, n, dp);
            if(ans) { // optimization
                return true;
            }
        }
        dp[i] = ans;
        return ans;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        int ans = state(0, nums, n, dp);
        return ans;
    }
};