class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 1 <= n <= 1e3 so O(n^2 logn) could work
        int n = nums.size();
        vector<vector<int>> ans;

        // o(n^2)
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            int j = i+1, k = n-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    int x = nums[i];
                    int y = nums[j];
                    int z = nums[k];
                    while((j < k) && (nums[j] == y)) {
                        j++;
                    }
                    while((j < k) && (nums[k] == z)) {
                        k--;
                    }
                    ans.push_back({x, y, z});
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
            while((i+1 < n) && (nums[i+1] == nums[i])) {
                i++;
            }
        }
        
        return ans;
    }
};