class Solution {
public:
    bool good(vector<int>& bitsPos, int k) {
        int sum = 0;
        for(int i=0; i<32; i++) {
            if(bitsPos[i]) {
                sum += (1 << i);
            }
            if(sum >= k) {
                return true;
            }
        }
        return false;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        // subarray == window
        // variable size window
        // bydefault monotonic increasing graph as 1 <= a[i] <= 1e9

        int mini = INT_MAX;
        int n = nums.size();

        // O(n^2) TLE
        // for(int i=0; i<n; i++) {
        //     int val = 0;
        //     for(int j=i; j<n; j++) {
        //         val = val | nums[j];
        //         if(val >= k) {
        //             mini = min(mini, j-i+1);
        //             break;
        //         }
        //     }
        // }

        vector<int> bitsPos(32, 0);
        int init = 0;
        // O(n) * O(32) = O(n)
        for(int i=0; i<n; i++) { // O(n)
            for(int bit=0; bit<32; bit++) { // O(32)
                if(nums[i] & (1 << bit)) {
                    bitsPos[bit]++;
                }
            }
            while(init <= i && good(bitsPos, k)) { // O(32)
                mini = min(mini, i-init+1);
                for(int bit=0; bit<32; bit++) { // O(32)
                    if(nums[init] & (1 << bit)) {
                        bitsPos[bit]--;
                    }
                }
                init++;
            }
        }

        if(mini >= INT_MAX) {
            return -1;
        }
        return mini;
    }
};