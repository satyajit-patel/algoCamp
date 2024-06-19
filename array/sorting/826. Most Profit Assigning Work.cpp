class Solution {
public:
    // 1 <= n, m <= 10^4
    // f(n) = O(n^2)

    int f(int x, auto& arr, auto& profit) {
        int ans = -1;
        int maxProfit = INT_MIN;

        // O(n)
        for(auto& it: arr) {
            if(it.first <= x && maxProfit < profit[it.second]) {
                ans = it.second;
                maxProfit = profit[it.second];
            }
        }

        return ans;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;

        vector<pair<int, int>> arr;
        for(int i=0; i<difficulty.size(); i++) {
            arr.push_back({difficulty[i], i});
        }
        sort(arr.begin(), arr.end()); // O(nlogn)

        // O(n * n)
        for(auto& it: worker) {
            int index = f(it, arr, profit);
            ans += (index== -1) ? (0) : (profit[index]);
        }

        return ans;
    }
};