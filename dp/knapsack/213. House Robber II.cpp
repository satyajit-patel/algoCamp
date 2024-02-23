/*
        Input: nums = [1,2,3,1]
        Output: 4
        Explanation: 
        Rob house 1 (money = 1) and then rob house 3 (money = 3).
        Total amount you can rob = 1 + 3 = 4.

        Constraints:
        1 <= nums.length <= 100
        0 <= nums[i] <= 1000

        expected f(n) = O(n^4)
        our f(n) = exponential(2^n) with recursion, O(n) with dp
    */

    int state(int i, auto& A, int n, auto& dp) {
        // base case
        if(i >= n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        // transition
        int pick = A[i] + state(i+2, A, n, dp);
        int notPick = state(i+1, A, n, dp);
        int ans = max(pick, notPick);
        dp[i] = ans;
        return ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        vector<int> dp(n+1, -1);
        int case1 = state(0, nums, n-1, dp);

        dp.clear(), dp.resize(n+1, -1);
        int case2 = state(1, nums, n, dp);

        int ans = max(case1, case2);
        return ans;
    }