class Solution {
public:
    /*
        Input: nums = [2,5,7,8,9,2,3,4,3,1]
        Output: 3

        blocks: 2,5,7,8,9 2,3,4, 3, 1
        blocks: 5, 3, 1, 1

    */

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> blocks;
        int count = 0;
        for(int i=0; i<n; i++) {
            count++;
            if(i == n-1 || nums[i] >= nums[i+1]) {
                blocks.push_back(count);
                count = 0;
            }
        }
        for(auto& it: blocks) {
            cout << it << " ";
        }
        int len = blocks.size();
        int maxi = INT_MIN;
        for(int i=0; i<len-1; i++) {
            maxi = max(maxi, min(blocks[i], blocks[i+1]));
        }
        // if all are in increasing order
        for(int i=0; i<len; i++) {
            maxi = max(maxi, blocks[i]/2);
        }
        return maxi;
    }
};