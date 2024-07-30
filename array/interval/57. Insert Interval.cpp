class Solution {
public:
    /*
        Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
        Output: [[1,5],[6,9]]
                            sort
        [[1,3],[6,9],[2,5]] ====> [[1,3],[2,5],[6,9]] ==> [[1,5],[6,9]]
    */

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        intervals.push_back(newInterval);
        std::sort(intervals.begin(), intervals.end());

        for(auto& row: intervals) {
            if(ans.empty() || row[0] > ans[ans.size()-1][1]) {
                ans.push_back(row);
            } else {
                ans[ans.size()-1][1] = std::max(ans[ans.size()-1][1], row[1]);
            }
        }

        return ans;
    }
};