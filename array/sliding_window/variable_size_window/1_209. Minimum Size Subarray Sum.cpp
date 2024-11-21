class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // subarray == window
        // this is variable size window
        // contains only +ve integers
        int ans = INT_MAX;

        int n = nums.size();
        int sum = 0;
        int init = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            while(sum >= target) {
                ans = min(ans, i-init+1);
                sum -= nums[init];
                init++;
            }
        }

        return ans != INT_MAX ? ans : 0;
    }
};