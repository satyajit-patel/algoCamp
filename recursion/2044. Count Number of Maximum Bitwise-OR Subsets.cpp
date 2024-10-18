#define vvi vector<vector<int>>
class Solution {
public:
    /*
        Input: nums = [3,2,1,5]
        Output: 6
        Explanation: The maximum possible bitwise OR of a subset is 7. 
        There are 6 subsets with a bitwise OR of 7:
        - [3,5]
        - [3,1,5]
        - [3,2,5]
        - [3,2,1,5]
        - [2,5]
        - [2,1,5]
    */
    int f(int i, int sum, vector<int>& nums, int maxi, vvi& dp) {
        // base case
        if(i >= nums.size()) {
            return sum == maxi;
        }
        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }

        // transition
        int take = f(i+1, sum | nums[i], nums, maxi, dp);
        int notTake = f(i+1, sum, nums, maxi, dp);
        return dp[i][sum] = take + notTake;
    }

    int state(int i, vector<int>& nums, int n, int maxi, vector<int>& ds) {
        // base case
        if(i >= n) {
            int sum = 0;
            for(auto& it: ds) {
                sum = sum | it;
            }
            // cout << sum << " -> " << endl;
            if(sum == maxi) {
                return 1;
            }
            return 0;
        }

        // transition
        ds.push_back(nums[i]);
        int take = state(i+1, nums, n, maxi, ds);
        ds.pop_back();
        int notTake = state(i+1, nums, n, maxi, ds);
        return take + notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(auto& it: nums) {
            sum = sum | it;
            maxi = max(maxi, sum);
        }
        // vector<int> ds;
        // int ans = state(0, nums, n, maxi, ds); // 2^16 AC either
        vector<vector<int>> dp(n+1, vector<int>(maxi+1, -1));
        int ans = f(0, 0, nums, maxi, dp); // O(n * maxi)
        return ans;
        // return maxi;
    }
};