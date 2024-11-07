class Solution {
public:
    int maxSize;
    int maxValue;

    void state(int i, vector<int>& nums, int curVal, int curSize) {
        // base case
        if(i >= nums.size()) {
            if(curVal > maxValue && curSize > maxSize) {
                maxValue = curVal;
                maxSize = curSize;
            }
            return;
        }

        // transition
        // take
        int x = curVal & nums[i];
        // cout << x << endl;
        state(i+1, nums, x, curSize + 1);
        // notTake
        state(i+1, nums, curVal, curSize);
    }

    int f(vector<int>& candidates) {
        int maxSize = 0;
        // There are 32 bits in a standard int (assuming 32-bit integers)
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            for (int num : candidates) {
                // Check if the bit at position 'bit' is set in 'num'
                if (num & (1 << bit)) {
                    ++count;
                }
            }
            // Update maxSize with the maximum count of set bits in any position
            maxSize = max(maxSize, count);
        }
        return maxSize;
    }

    int largestCombination(vector<int>& candidates) {
        // maxSize = 0;
        // maxValue = 0;
        // // return 1 & 9; // 0001 & 1001 = 0001 = 1
        // state(0, candidates, INT_MAX, 0); // O(2^n) TLE
        // return maxSize;
        return f(candidates); // O(n) + O(32) = O(n)
    }
};