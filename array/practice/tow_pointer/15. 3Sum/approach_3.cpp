class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 1 <= n <= 1e3 so O(n^2 logn) could work
        int n = nums.size();
        vector<vector<int>> ans;

        // o(n^2 logn)
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                // let nums[i] + nums[j] + x = 0
                // x = 0 - nums[i] - nums[j]
                int x = 0 - nums[i] - nums[j];
                if(binary_search(nums.begin()+j+1, nums.end(), x)) {
                    st.insert({nums[i], nums[j], x});
                } 
            }
        }
        for(auto& it: st) {
            ans.push_back(it);
        }

        return ans;
    }
};