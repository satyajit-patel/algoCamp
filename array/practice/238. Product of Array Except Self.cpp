class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left(n);
        vector<int> right(n);

        int mul = 1;
        for(int i=0; i<n; i++) {
            mul *= nums[i];
            left[i] = mul;;
        }

        mul = 1;
        for(int i=n-1; i>=0; i--) {
            mul *= nums[i];
            right[i] = mul;
        }

        for(int i=0; i<n; i++) {
            if(i == 0) {
                ans[i] = right[i+1];
                continue;
            }
            if(i == n-1) {
                ans[i] = left[i-1];
                continue;
            }
            ans[i] = left[i-1] * right[i+1];
        }
        return ans;
    }
};