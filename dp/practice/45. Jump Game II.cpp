class Solution {
public:
    vector<int> dp;
    int state(int i, vector<int>& nums) {
        // base case
        if(i >= nums.size()-1) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        // transition
        int mini = 1e9;
        for(int step=1; step<=nums[i]; step++) {
            mini = std::min(mini, 1 + state(i+step, nums));
        }
        return dp[i] = mini;
    }

    int jump(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);
        // it's guarantee that we will always have ans
        int ans = state(0, nums);
        return ans;
    }
};