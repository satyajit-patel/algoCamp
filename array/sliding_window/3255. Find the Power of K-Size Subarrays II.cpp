class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) {
            return nums;
        }

        int n = nums.size();
        int size = n - k + 1;
        vector<int> ans(size, -1);

        int i = 1;
        int l = 0;
        while(i < n) {
            if(nums[i] == nums[i-1]+1) {
                if(i-l+1 == k) {
                    ans[l] = nums[i];
                    i++;
                    l++;
                } else {
                    i++;
                } 
            } else {
                l = i;
                i++;
            }
        }

        return ans;
    }
};