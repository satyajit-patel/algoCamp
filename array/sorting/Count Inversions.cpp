// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
class Solution {
public:
    long long merge(int l, int mid, int r, vector<long long>& nums) {
        int n = mid-l+1;
        int m = r-mid;
        long long a[n];
        long long b[m];
        for(int i=0; i<n; i++) {
            a[i] = nums[i + l];
        }
        for(int i=0; i<m; i++) {
            b[i] = nums[i + (mid+1)];
        }
        int i = 0;
        int j = 0;
        long long inv = 0;
        while(i < n && j < m) {
            if(a[i] <= b[j]) {
                nums[l++] = a[i++];
            } else {
                nums[l++] = b[j++];
                inv += (n-1) - i + 1;
            }
        }
        while(i < n) {
            nums[l++] = a[i++];
        }
        while(j < m) {
            nums[l++] = b[j++];
        }
        return inv;
    }

    long long ms(int i, int j, vector<long long>& nums) {
        // base case
        if(i >= j) { // smart guy
            return 0;
        }
        
        // transition
        int mid = (i + j) / 2;
        long long x = ms(i, mid, nums);
        long long y = ms(mid+1, j, nums);
        long long z = merge(i, mid, j, nums);
        long long inv = x + y + z;
        return inv;
    }

    long long int inversionCount(vector<long long>& arr) {
        /*
            [2, 4, 1, 3, 5]
            // bubble sort logic
            => [2, 1, 3, 4, 5] - 2 swap
            => [1, 2, 3, 4, 5] - 1 swap
            total 3 swap needed to sort
        */
        int n = arr.size();
        long long inv = ms(0, n-1, arr);
        // for(auto& it: arr) {
        //     cout << it << " ";
        // }
        // cout << endl;
        return inv;
    }
};