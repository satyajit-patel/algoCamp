/*
        Constraints:
        1 <= points.length <= 10^5
        points[i].length == 2
        -2^31 <= xstart < xend <= 2^31 - 1

        Input: points = [[10,16],[2,8],[1,6],[7,12]]
        Output: 2
        Input: points = [[1,2],[3,4],[5,6],[7,8]]
        Output: 4
    */

    struct comp {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        }
    };

    int findMinArrowShots(vector<vector<int>>& points) {
        // sort according to last ele, 
        // so that overlapping line will come together
        sort(points.begin(), points.end(), comp());
        int ans = 1;
        int lastEnd = points[0][1];
        for(int i=1; i<points.size(); i++) {
            if(points[i][0] > lastEnd) {
                ans++;
                lastEnd = points[i][1];
            }
        }
        return ans;
    }