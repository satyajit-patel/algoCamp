class Solution {
public:    
    long long int maxSumWithK(long long a[], long long n, long long k) {
        
        // // O(N^2) TLE
        // long long maxSum = INT_MIN;
        // for(long long i=0; i<n; i++) {
        //     long long curSum = 0;
        //     for(long long j=i; j<n; j++) {
        //         curSum += a[j];
        //         if(j-i+1 >= k && curSum > maxSum) {
        //             maxSum = curSum;
        //         }
        //     }
        // }
        // return maxSum;
        
        // O(N)
        long long maxSum = INT_MIN;
        long long frontSum = 0, backSum = 0;
        long long i = 0, j = 0;
        while(i < n && j < n) {
            frontSum += a[j];
            long long subarraySize = j-i+1;
            if(subarraySize < k) {
                j++;
            } else if(subarraySize == k) {
                maxSum = max(maxSum, frontSum);
                j++;
            } else if(subarraySize > k) {
                maxSum = max(maxSum, frontSum);
                backSum += a[i];
                i++;
                if(backSum < 0) {
                    frontSum -= backSum;
                    maxSum = max(maxSum, frontSum);
                    backSum = 0;
                }
                j++;
            }
        }
        return maxSum;
    }
};
