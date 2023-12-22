class Solution {
public:
    int lenOfLongSubarr(int nums[],  int n, int k) { 
        // O(N * LogN) -> if ordered map
        // omega(N * 1) or O(n * n) -> if unordered_map
        int ans = 0;
        int sum = 0;
        map<int, int> map;
        for(int i=0; i<n; i++) {
            // work
            sum += nums[i];

            // update
            if(sum == k) {
                int window_size = i+1;
                ans = max(ans, window_size);
            }
            if(map.count(sum-k)) {
                int window_size = i-map[sum-k];
                ans = max(ans, window_size);
            }

            // insert
            if(!map.count(sum)) {
                map[sum] = i;
            }
        }
        return ans;
    } 
};