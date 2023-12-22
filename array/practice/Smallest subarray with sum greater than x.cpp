class Solution {
public:
    int smallestSubWithSum(int arr[], int n, int x) {
        // 1 <= n <= 1e5
        // expected O(nlogn)
        int ans = INT_MAX;
        int i=0, j=0, sum = 0;
        while(i<n && j<n) {
            sum += arr[j];
            // cout<<sum<<endl;
            while(sum > x) {
                ans = min(ans, j-i+1);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        if(ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};