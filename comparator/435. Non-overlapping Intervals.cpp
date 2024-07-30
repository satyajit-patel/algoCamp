class compClass {
public:
    bool operator()(vector<int>& a, vector<int>& b) {
        if(a[1] == b[1]) {
            return a[0] > b[0];
        }
        return a[1] < b[1];
    }
};

class Solution {
public:
    /*
        here

            1________2 3--------4   // i.e not overlapping

                     2
            1________2--------4     // i.e not overlapping

                2----------4
            1_______3               // i.e overlapping
    */

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        std::sort(intervals.begin(), intervals.end(), compClass());

        for(auto& row: intervals) {
            if(ans.empty() || row[0] >= ans[ans.size()-1][1]) {
                ans.push_back(row);
            } else {
                // ans[ans.size()-1][1] = std::max(ans[ans.size()-1][1], row[1]);
            }
        }

        return intervals.size() - ans.size();
    }
};