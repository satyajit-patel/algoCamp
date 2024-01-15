class Solution {
public:
    int findMin(int arr[], int n) {
        int lo = 0;
        int hi = n - 1;
        while(lo <= hi) {
            if(arr[lo] < arr[hi]) {
                return arr[lo];
            }
            int mid = (lo + hi) / 2;
            if(mid-1 >= 0 && arr[mid] < arr[mid-1]) {
                return arr[mid];
            }
            if(mid+1 < n && arr[mid+1] < arr[mid]) {
                return arr[mid+1];
            }
            if(arr[lo] < arr[mid]) {
                // upper curve
                lo = mid + 1; // as ans is always gonna be in lowwr curve
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
};
