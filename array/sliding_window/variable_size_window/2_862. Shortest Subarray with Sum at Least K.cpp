class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // subarray == window
        // this is variable size window
        // contains both +ve and -ve integers, so we have to maintain the
        // monotonic increasing graph manually

        int mini = INT_MAX;

        int n = nums.size();
        vector<long long> ps(n+1, 0); // carefull for size
        for(int i=0; i<n; i++) {
            ps[i+1] = nums[i] + ps[i];
        }
        deque<pair<long long, int>> dq; // sc O(n), tc O(n)

        for(int i=0; i<=n; i++) { // carefull for index
            while(!dq.empty() && ps[i] < dq.back().first) {
                dq.pop_back();
            }

            while(!dq.empty() && ps[i] - dq.front().first >= k) {
                mini = min(mini, i-dq.front().second);
                dq.pop_front();
            }

            dq.push_back({ps[i], i});
        }

        return mini != INT_MAX ? mini : -1;
    }
};