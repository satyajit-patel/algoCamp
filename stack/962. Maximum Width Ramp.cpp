class Solution {
public:
    /*
        Input: nums = [9,8,1,0,1,9,4,0,4,1]
        Output: 7
        Explanation: The maximum width ramp is achieved 
        at (i, j) = (2, 9): 
        nums[2] = 1 and nums[9] = 1.
    */

    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> st;

        for(int i=0; i<n; i++) {
            // monotonic decreasing stack
            if(st.empty() || nums[i] < nums[st.back()]) {
                st.push_back(i);
            } else {
                int low = 0;
                int high = st.size() - 1;
                while(low <= high) {
                    int mid = (low + high) / 2;
                    if(nums[st[mid]] <= nums[i]) {
                        ans = max(ans, i - st[mid]);
                        // look for more on left
                        high = mid - 1;
                    } else {
                        low =  mid + 1;
                    }
                }
            }
        }
        return ans;
    }
};