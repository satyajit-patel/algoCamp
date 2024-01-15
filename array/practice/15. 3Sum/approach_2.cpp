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
            int j = i+1, k = n-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        for(auto& it: st) {
            ans.push_back(it);
        }

        return ans;
    }
};