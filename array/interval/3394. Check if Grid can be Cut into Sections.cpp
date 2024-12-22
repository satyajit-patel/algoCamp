class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> rows, cols, mergedRows, mergedCols;
        for(auto& it: rectangles) {
            rows.push_back({it[1], it[3]});
            cols.push_back({it[0], it[2]});
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        for(auto& it: rows) {
            if(mergedRows.empty() || it.first >= mergedRows.back().second) {
                mergedRows.push_back(it);
            } else {
                mergedRows.back().second = max(mergedRows.back().second, it.second);
            }
        }
        if(mergedRows.size() >= 3) {
            return true;
        }

        for(auto& it: cols) {
            if(mergedCols.empty() || it.first >= mergedCols.back().second) {
                mergedCols.push_back(it);
            } else {
                mergedCols.back().second = max(mergedCols.back().second, it.second);
            }
        }
        if(mergedCols.size() >= 3) {
            return true;
        }

        return false;
    }
};