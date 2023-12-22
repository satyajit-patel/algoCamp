class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 1 <= n <= 1e2 so O(n^4) could work
        int n = nums.size();
        // O(n^3 logn)
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    long long sum = 0;
                    sum += 1LL * (nums[i]);
                    sum += 1LL * (nums[j]);
                    sum += 1LL * (nums[k]);
                    // sum + x = target
                    long long x = target - sum;
                    if(binary_search(nums.begin()+k+1, nums.end(), x)) {
                        st.insert({nums[i], nums[j], nums[k], int(x)});
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto& it: st) {
            ans.push_back(it);
        }
        return ans;
    }
};