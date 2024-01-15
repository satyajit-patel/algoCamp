class Solution {
public:
    bool good(int mid, int* arr, int N, int K) {
        int numOfSubarray = 1;
        int sum = 0;
        for(int i=0; i<N; i++) {
            sum += arr[i];
            if(sum > mid) {
                numOfSubarray += 1;
                sum = arr[i];
            }
        }
        return numOfSubarray <= K;
    }
    
    int totSum(int* arr, int N) {
        int sum = 0;
        for(int i=0; i<N; i++) {
            sum += arr[i];
        }
        return sum;
    }

    int splitArray(int arr[] ,int N, int K) {
        int ans = -1;
        int lo = *max_element(arr, arr+N);
        int hi = totSum(arr, N);
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(good(mid, arr, N, K)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};