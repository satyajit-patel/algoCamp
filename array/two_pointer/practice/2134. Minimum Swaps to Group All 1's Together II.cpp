class Solution {
public:
    /*
        Input: nums = [1,1,1,0,0,1,0,1,1,0]
        Output: 1
    */

    int minSwaps(vector<int>& nums) {
        int totOne = 0; // becomes window size
        bool isNoOne = true;
        for(auto& it: nums) {
            if(it == 1) {
                isNoOne = false;
                totOne++;
            }
        }
        if(isNoOne) {
            return 0;
        }

        nums.insert(nums.end(), nums.begin(), nums.end());
        int n = nums.size();

        // sliding window
        int init = 0;
        int maxOne = 0;
        int i = 0;

        int curOne = 0;
        while(i < n) {
            if(nums[i] == 1) {
                curOne++;
            }
            if(i-init+1 == totOne) {
                maxOne = std::max(maxOne, curOne);
                if(nums[init] == 1) {
                    curOne--;
                }
                i++;
                init++;
            } else {
                i++;
            }
        }

        return totOne - maxOne;
    }
};