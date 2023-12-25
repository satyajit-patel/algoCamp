class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // search space
        int lo = 0, hi = nums.size()-1;
        while(lo < hi) {
            int mid = (lo+hi)/2;
            // if in decreasing order
            if(nums[mid] > nums[mid+1]) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
};