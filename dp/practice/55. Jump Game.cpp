class Solution {
public:
    vector<int> dp;
    bool state(int i, vector<int>& nums) {
        // base case
        if(i >= nums.size()-1) {
            return true;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        // transition
        for(int step=1; step<=nums[i]; step++) {
            if(state(i+step, nums)) {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);
        bool ans = state(0, nums);
        return ans;
    }
};