class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // int n = nums.size();
        // int maxLenSubarray = 0;

        // int i = 0;
        // int j = 0;
        // priority_queue<pair<int, int>> maxPq;
        // priority_queue<pair<int, int>> minPq;
        // while(j < n) {
        //     maxPq.push({nums[j], j});
        //     minPq.push({nums[j] * -1, j});
        //     while(maxPq.top().first-(minPq.top().first*-1) > limit) {
        //         i = min(maxPq.top().second, minPq.top().second) + 1;
        //         while(maxPq.top().second < i) {
        //             maxPq.pop();
        //         }
        //         while(minPq.top().second < i) {
        //             minPq.pop();
        //         }
        //     }
        //     maxLenSubarray = max(maxLenSubarray, j-i+1);
        //     j++;
        // }

        // return maxLenSubarray;

        std::multiset<int> st;
        int init = 0;
        int maxLength = 0;
        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
            /*
                if the difference of max and min ele is > limit
                then there is no point in moving forward as all further diff will be
                also greater than limit. so
                we need to shrink now 
            */
            while(*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[init]));
                init++;
            }
            maxLength = std::max(maxLength, i-init+1);
        }
        return maxLength;
    }
};