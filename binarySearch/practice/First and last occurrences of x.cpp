class Solution {
public:
    vector<int> find(int arr[], int n , int x ) {
        vector<int> ans = {-1, -1};
        if(binary_search(arr, arr+n, x)) {
            int i = lower_bound(arr, arr+n, x) - arr;
            int j = upper_bound(arr, arr+n, x) - arr;
            j--;
            ans[0] = i;
            ans[1] = j;
            return ans;
        }
        return ans;
    }
};