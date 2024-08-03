/*
        Input: nums = [10,5,2,6], k = 100
        Output: 8
        Explanation: 
        The 8 subarrays that have product less than 100 are:
        [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
        Note that [10, 5, 2] 
        is not included as the product of 100 is not strictly less than k.

        Constraints:
        1 <= nums.length <= 3 * 104
        1 <= nums[i] <= 1000
        0 <= k <= 106
    */

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans  = 0;

        // for(int i=0; i<nums.size(); i++) {
        //     long long product = 1;
        //     for(int j=i; j<nums.size(); j++) {
        //         product *= (long long)nums[j];
        //         if(product < k) {
        //             ans++;
        //         } else {
        //             // time save
        //             break;
        //         }
        //     }
        // }

        int init = 0;
        /*
            x * y = k;
            x = k/y;
        */
        int product = 1;
        for(int i=0; i<nums.size(); i++) {
            product *= nums[i];

            while(product >= k && init <= i) {
                product /= nums[init];
                init++;
            }

            if(product < k) {
                ans += (i - init + 1);
            }
        }

        return ans;
    }