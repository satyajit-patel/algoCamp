class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // search space
        int lo = 0, hi = nums.size()-1;
        while(lo < hi) {
            int mid = (lo+hi)/2;
            // size excluding mid
            bool isRightSideEven = (hi-mid)%2 == 0; 
            if(nums[mid] == nums[mid+1]) {
                if(isRightSideEven) {
                    lo = mid + 2;
                } else {
                    hi = mid - 1;
                }
            } else if(nums[mid] == nums[mid-1]) {
                if(isRightSideEven) {
                    hi = mid - 2;
                } else {
                    lo = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[lo];
    }
};