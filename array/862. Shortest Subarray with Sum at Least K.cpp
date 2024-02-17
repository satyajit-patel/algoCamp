/*
        Example 3:
        Input: nums = [2,-1,2], k = 3
        Output: 3

        Constraints:
        1 <= nums.length <= 105
        -105 <= nums[i] <= 105
        1 <= k <= 109
    */
    int shortestSubarray(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int n= nums.size();
        // 1 based indexing as 0 at front doen't affact but help
        vector<long long> prefixSum(n+1, 0); // checkout for overflow
        for(int i=0; i<n; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        // now
        // we have to take deque to maintain monotonic graph
        // as array contains -ve ele also
        deque<pair<long long, int>> dq; // {ele, index}
        for(int i=0; i<=n; i++) {
            // maintain the monotonic graph
            while(!dq.empty() && prefixSum[i] < dq.back().first) {
                dq.pop_back();
            }

            // take out ans
            while(!dq.empty() && prefixSum[i]-dq.front().first >= k) {
                mini = min(mini, i - dq.front().second);
                dq.pop_front();
            }

            dq.push_back({prefixSum[i], i});
        }
        if(mini == INT_MAX) {
            return -1;
        }
        return mini;
    }