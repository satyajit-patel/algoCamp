class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            // nums[i] + x >= lower
            int x = lower - nums[i];
            // nums[i] + y <= upper
            int y = upper - nums[i];
            int lb = lower_bound(nums.begin()+i+1, nums.end(), x) - nums.begin();
            int ub = upper_bound(nums.begin()+i+1, nums.end(), y) - nums.begin();
            ans += (ub - lb);
        }
        return ans;
    }
};