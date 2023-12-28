class Solution {
public:
    bool good(long long mid, int* arr, int n, int k) {
        int numOfPainters = 1;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            sum += 1LL * arr[i];
            if(sum > mid) {
                numOfPainters++;
                sum = arr[i];
            }
        }
        // can we do this in atmost k worker
        return numOfPainters <= k;
    }

    long long minTime(int arr[], int n, int k) {
        long long ans = -1;
        long long maxi = INT_MIN;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            maxi = max(maxi, 1LL * arr[i]);
            sum += 1LL * arr[i];
        }
        long long lo = maxi;
        long long hi = sum;
        while(lo <= hi) {
            long long mid = (lo+hi)/2;
            if(good(mid, arr, n, k)) {
                ans = mid;
                // look for further minimum
                hi = mid - 1; 
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};