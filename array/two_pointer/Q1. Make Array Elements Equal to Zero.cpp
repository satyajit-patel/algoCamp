class Solution {
public:
// https://leetcode.com/contest/weekly-contest-424/problems/make-array-elements-equal-to-zero/description/
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(), lps[n], rps[n], sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            lps[i] = sum;
        }
        sum = 0;
        for(int i=n-1; i>=0; i--) {
            sum += nums[i];
            rps[i] = sum;
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                continue;
            }
            int diff = abs(lps[i] - rps[i]);
            if(diff == 0) {
                ans += 2;
            } else if(diff == 1) {
                ans += 1;
            }
        }
        return ans;
    }
};