class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto& it: nums) {
            st.insert(it);
        }
        int n = nums.size();
        if(st.empty()) {
            return 0;
        }
        if(st.size() == 1) {
            return 1;
        }
        int len = 1;
        int ans = INT_MIN;
        auto it = st.begin();
        it++;
        for(it; it != st.end(); it++) {
            auto dummyIt = it;
            dummyIt--;
            if((*it) - (*dummyIt) == 1) {
                len++;
            }
            else {
                len = 1;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};