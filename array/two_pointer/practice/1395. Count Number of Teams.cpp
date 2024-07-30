class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;

        // O(n logn)
        vector<int> leftMinCount, leftMaxCount;
        set<int> st;
        for(auto& it: rating) {
            int count = std::distance(st.begin(), st.lower_bound(it));
            leftMinCount.push_back(count);
            leftMaxCount.push_back(st.size() - count);
            st.insert(it);
        }
        // // check
        // for(int i=0; i<n; i++) {
        //     cout<<leftMinCount[i]<<" ";
        // }
        vector<int> rightMinCount, rightMaxCount;
        st.clear();
        std::reverse(rating.begin(), rating.end());
        for(auto& it: rating) {
            int count = std::distance(st.begin(), st.lower_bound(it));
            rightMinCount.push_back(count);
            rightMaxCount.push_back(st.size() - count);
            st.insert(it);
        }
        std::reverse(rating.begin(), rating.end()); // back to normal
        std::reverse(rightMinCount.begin(), rightMinCount.end());
        std::reverse(rightMaxCount.begin(), rightMaxCount.end());
        // // check
        // for(int i=0; i<n; i++) {
        //     cout<<rightMinCount[i]<<" ";
        // }

        for(int i=1; i<n-1; i++) {
            // 1 2 3
            if(leftMinCount[i] > 0 && rightMaxCount[i] > 0) {
                ans += (leftMinCount[i] * rightMaxCount[i]);
            }
            // 3 2 1
            if(leftMaxCount[i] > 0 && rightMinCount[i] > 0) {
                ans += (leftMaxCount[i] * rightMinCount[i]);
            } 
        }

        return ans;
    }
};