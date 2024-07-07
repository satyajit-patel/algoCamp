class Solution {
public:
    int findMin(vector<int>& nums) {
        // // O(n)
        // return *std::min_element(nums.begin(), nums.end());

        // O(log n)
        int i = 0;
        int j = nums.size() - 1;
        int mini = INT_MAX;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(nums[i] <= nums[mid]) {
                // sorted portion
                mini = std::min(mini, nums[i]);
                i = mid + 1; // eleminate left part
            } else {
                // sorted portion
                mini = std::min(mini, nums[mid]);
                j = mid - 1; // eleminate right part
            }
        }
        return mini;
    }
};