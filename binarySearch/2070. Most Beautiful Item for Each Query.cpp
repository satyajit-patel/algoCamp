class Solution {
public:
    /*
        Input: 
            items = [[1,2],[3,2],[2,4],[5,6],[3,5]], 
            queries = [1,2,3,4,5,6]
        Output: 
            [2,4,5,5,6,6]
    */

    int f(int money, vector<vector<int>>& items) {
        int i = 0;
        int j = items.size() - 1;
        int ans = 0;

        while(i <= j) {
            int mid = (i + j) / 2;
            if(items[mid][0] <= money) {
                // cout << money << " " << items[mid][1] << endl;
                ans = max(ans, items[mid][1]);
                // look for more maximum
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int maxi = INT_MIN;
        for(int i=0; i<items.size(); i++) {
            maxi = max(maxi, items[i][1]);
            items[i][1] = maxi;
        }
        vector<int> ans;
        for(auto& it: queries) {
            ans.push_back(f(it, items));
        }
        return ans;
    }
};