class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        // contraints are only +ve
        int n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        // O(2N) = O(N)
        // O(N) because we are touching every element only once
        // and every iteration we have constant operation
        // here for 1 or 2 iteration only we have close to "N-1" operation
        // thats why its gets added with final operation and becomes O(2N)
        // if that would have been (n-1) operation for each iteration
        // then it would have been O(N * N) 
        for(int i=0, j=0; i<n && j<n; j++) {
            sum += nums[j];
            while(sum >= k && i<=j) {
                int unique_window_size = j-i+1;
                ans = min(ans, unique_window_size);
                sum -= nums[i];
                i++;
            }
        }
        if(ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};