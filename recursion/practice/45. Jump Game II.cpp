class Solution {
public:
    int state(int i, vector<int>& nums, int n, vector<int>& dp) {
        // base case
        if(i == n-1) {
            return 0;
        }
        if(i >= n) {
            return 1e9;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        // transition
        int mini = 1e9;
        for(int j=1; j<=nums[i]; j++) {
            mini = std::min(mini, 1+state(i+j, nums, n, dp));
        }
        dp[i] = mini;
        return mini;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        int ans = state(0, nums, n, dp);
        return ans;
    }
};