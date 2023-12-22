class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // observation :
        // 0 is neither +ve nor -ve
        // -ve num will never contribute to our ans
        // ans will never be > n
        int n = nums.size();
        int containsOne = false;
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) {
                containsOne = true;
                break;
            }
        }
        if(!containsOne) {
            return 1;
        }
        for(int i=0; i<n; i++) {
            if(nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }
        for(int i=0; i<n; i++) {
            int x = abs(nums[i]);
            if(x == n) {
                nums[0] = - abs(nums[0]);
            }
            else {
                nums[x] = - abs(nums[x]);
            }
        }
        for(int i=1; i<n; i++) {
            if(nums[i] > 0) {
                return i;
            }
        }
        if(nums[0] > 0) {
            return n;
        }
        return n+1;
    }
};