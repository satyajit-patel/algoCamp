class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        multiset<int> st;
        int init = 0;
        // O(nlogn)
        for(int i=0; i<n; i++) { // O(n)
            st.insert(nums[i]);
            if(i-init+1 == k) {
                ans.push_back(*st.rbegin());
                // st.erase is O(n) where "n" is number of elements deleted
                st.erase(st.find(nums[init])); // so here O(1)
                init++;
            }
        }

        return ans;
    }
};