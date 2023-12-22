#define ll long long
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = INT_MAX;
        vector<ll> pre(n+1, 0);
        for(ll i=0; i<n; i++) {
            pre[i+1] = nums[i] + pre[i];
        }
        deque<ll> dq;
        for(ll i=0; i<=n; i++) {
            // work
            while(!dq.empty() && pre[i] <= pre[dq.back()]) {
                dq.pop_back();
            }

            // update
            while(!dq.empty() && pre[i]-pre[dq.front()] >= k) {
                ll window_size = i - dq.front();
                ans = min(ans, window_size);
                dq.pop_front();
            }

            // insert
            dq.push_back(i);
        }
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};