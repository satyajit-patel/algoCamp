class Solution {
public:
    void _2_pointer(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        // maintain the decreasing order
        while(i>=0 && nums[i] >= nums[i+1]) {
            i--;
        }
        if(i >= 0) {
            int j = n-1;
            while(nums[j] <= nums[i]) {
                j--;
            }
            // replace with just next greater element than nums[i]
            swap(nums[i], nums[j]);
        }
        // reverse the rest part to find even smallar
        // which will be just greater than nums
        reverse(nums.begin()+i+1, nums.end());
    }

    void nextPermutation(vector<int>& nums) {
        // int flag = 0;
        // do {
        //     if(flag == 1) {
        //         break;
        //     }
        //     flag++;
        // }while(next_permutation(nums.begin(), nums.end()));

        _2_pointer(nums);
    }
};