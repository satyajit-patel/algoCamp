class Solution {
public:
    /*
        0000
        0001
        0001
        0011
    ____________
        0011
    */
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;

        // TLE
        // while(!nums.empty()) { // O(n)
        //     int xorVal = 0;
        //     for(int i=0; i<nums.size(); i++) { // O(n)
        //         xorVal ^= nums[i];
        //     }
        //     nums.pop_back();
        //     int maxiVal = 0;
        //     int maxiBit = 0;
        //     for(int i=0; i<(1 << maximumBit); i++) { // O(2^20)
        //         int calc = i ^ xorVal;
        //         if(calc > maxiVal) {
        //             maxiVal = calc;
        //             maxiBit = i;
        //         }
        //     }
        //     ans.push_back(maxiBit);
        // }

        // bitmask(fixing a mask)
        int mask = (1 << maximumBit) - 1; // O(1)
        vector<int> v(nums.size());
        int x = 0;
        for(int i=0; i<nums.size(); i++) { // O(n)
            x ^= nums[i];
            v[i] = x; 
        }
        while(!v.empty()) { // O(n)
            int xorVal = v[v.size()-1]; // O(1)
            v.pop_back();
            int calc = mask ^ xorVal; // as mask and result are vice-versa
            ans.push_back(calc);
        }

        return ans;
    }
};