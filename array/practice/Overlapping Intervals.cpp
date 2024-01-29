class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i=0; i<n; i++) {
            int lastInterval = ans[ans.size()-1][1];
            int firstInterval = intervals[i][0];
            if(firstInterval <= lastInterval) {
                int curLastInterval = intervals[i][1];
                ans[ans.size()-1][1] = max(lastInterval, curLastInterval);
            } else {
                ans.push_back(intervals[i]);  
            }
        }
        return ans;
    }
};
