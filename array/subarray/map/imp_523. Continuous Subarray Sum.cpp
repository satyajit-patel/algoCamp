class Solution {
public:
    // 1 <= nums.length <= 10^5 => f(n) = O(n logn)

    bool checkSubarraySum(vector<int>& nums, int k) {

        // // TLE 94/99
        // for(int i=0; i<nums.size(); i++) {
        //     int sum = 0;
        //     int length = 0;
        //     for(int j=i; j<nums.size(); j++) {
        //         sum += nums[j];
        //         length++;
        //         if(length >= 2) {
        //             if(sum%k == 0) {
        //                 return true;
        //             }
        //         }
        //     }                                                                                                                                                                                                                    
        // }
        // return false;

        /*
            concept:
                interesting fact:
                let n1 % k = reminder1
                now if we add any multiple of k in n1
                it will result the same reminder i.e whatever sum we got to add extra in "n1"
                that sum must ne a multiple/divisible of k
                example
                    (1) % 4 = 1
                    (1+4) % 4 = 1
                    (1+12) % 4 = 1   
                example
                    (1) % 4 = 1
                    (1+2) % 4 = 2
                    (1+2+6) % 4 = 1 (now we have seen this reminder before)
                    so what ever extra sum(2+6) we added in initial num(1) that sum
                    must have been a multiple of k

        */
        map<int, int> map;
        int sum = 0;
        map[sum] = -1;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            int reminder = sum % k;
            if(map.find(reminder) != map.end()) {
                int subarraySize = i - map[reminder];
                if(subarraySize >= 2) {
                    return true;
                }
            } else {
                map[reminder] = i;
            }
        }
        return false;
    }
};