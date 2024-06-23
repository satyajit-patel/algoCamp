class Solution {
public:
    /*
        Input: nums = [1,1,2,1,1], k = 3
        Output: 2
        Explanation: 
        The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

        Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
        Output: 16
    */

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        // // AC
        // int oddCount = 0;
        // map<int, int> mp;
        // mp[oddCount]++;

        // for(int i=0; i<n; i++) {
        //     oddCount += (nums[i] & 1);

        //     if(mp.count(oddCount - k)) {
        //         ans += mp[oddCount - k];
        //     }

        //     mp[oddCount]++; 
        // }

        int init = 0;
        int oddCount = 0;
        int num_subarray = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] & 1) {
                oddCount++;
                num_subarray = 0;
            }

            while(oddCount == k) {
                num_subarray++;
                
                if(nums[init++] & 1) {
                    oddCount--;
                }
            }

            ans += num_subarray;
            // cout<<i<<" "<<num_subarray<<endl;
        }

        return ans;
    }
};