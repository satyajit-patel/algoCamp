class Solution {
public:
    vector<int> subarraySum(vector<int>arr, int n, long long s) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        long long sum = 0;
        while(i<n && j<n) {
            sum += 1LL * arr[j];
            while(sum>s && i<=j) {
                sum -= arr[i];
                i++;
            }
            if(sum==s && i<=j) {
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            j++;
        }
        return {-1};
    }
};