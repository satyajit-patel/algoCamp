class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(target == nums[mid]) {
                return mid;
            } else if(nums[i] <= nums[mid]) {
                // it is sorted part
                if(target >= nums[i] && target <= nums[mid]) {
                    j = mid - 1; // eleminate right part
                } else {
                    i = mid + 1; // eleminate left part
                }
            } else {
                // it is sorted part
                if(target >= nums[mid] && target <= nums[j]) {
                    i = mid + 1; // eleminate left part
                } else {
                    j = mid - 1; // eleminate right part
                }
            }
        }
        return -1;
    }
};