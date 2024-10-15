class Solution {
public:
    /*
        Example 1:
        Input: nums = [1,3,5,6], target = 5
        Output: 2

        Example 2:
        Input: nums = [1,3,5,6], target = 2
        Output: 1
        
        Example 3:
        Input: nums = [1,3,5,6], target = 7
        Output: 4
    */

    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int ans = n;
        // O(log n)
        while(i <= j) {
            int mid = (i + j) / 2;
            if(nums[mid] >= target) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }
};