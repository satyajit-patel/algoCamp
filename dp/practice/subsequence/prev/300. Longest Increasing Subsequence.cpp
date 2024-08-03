class Solution {
public:
    vector<vector<int>> dp;
    int state(int i, int prev, vector<int>& nums) {
        // base case
        if(i >= nums.size()) {
            return 0;
        }
        if(dp[i][prev+1] != -1) {
            return dp[i][prev+1];
        }

        // transition
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]) {
            take = 1 + state(i+1, i, nums);
        }
        int notTake = state(i+1, prev, nums);

        int ans = std::max(take, notTake);
        dp[i][prev+1] = ans;
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size()+1, vector<int>(nums.size()+1, -1));
        int ans = state(0, -1, nums);
        return ans;
    }
};