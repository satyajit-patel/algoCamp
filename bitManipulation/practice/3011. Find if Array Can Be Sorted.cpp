class Solution {
public:
    /*
        [8,4,2,30,15]
        [4,2,8,30,15] // after 1st iteration
        [4,2,8,15,30] // after 2nd iteration
    */

    bool isSameSetBits(vector<int>& nums) {
        bool flag = false;

        int lastSetCount = 0;
        for(int bit=0; bit<32; bit++) {
            if(nums[0] & (1 << bit)) {
                lastSetCount++;
            }
        }

        for(int i=1; i<nums.size(); i++) {
            int curSetCount = 0;
            for(int bit=0; bit<32; bit++) {
                if(nums[i] & (1 << bit)) {
                    curSetCount++;
                }
            }
            if(curSetCount == lastSetCount) {
                if(nums[i-1] > nums[i]) {
                    flag = true;
                    swap(nums[i-1], nums[i]);
                }
            }
            lastSetCount = curSetCount;
        }
        return flag;
    }

    bool canSortArray(vector<int>& nums) {
        while(1) {
            if(isSameSetBits(nums)) {
                if(is_sorted(nums.begin(), nums.end())) {
                    return true;
                }
            } else {
                break;
            }
        }
        return is_sorted(nums.begin(), nums.end());
    }
};