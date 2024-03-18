/*
        Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
        Output: [[1,5],[6,9]]
    */

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        intervals.push_back(newInterval);
        // O(n logn)
        sort(intervals.begin(), intervals.end());
        // O(n)
        for(int i=0; i<intervals.size(); i++) {
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        
        // n logn + n = O(n logn)
        return ans;
    }