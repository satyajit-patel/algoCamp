class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> grid;
    int N;
    int K;

    int state(int i, int jobs) {
        // base case
        if(i >= N) {
            return 0;
        }
        if(jobs >= K) {
            return 0;
        }
        if(dp[i][jobs] != -1) {
            return dp[i][jobs];
        }

        // transition
        vector<int> vec = {grid[i][1], INT_MAX, INT_MAX};
        int nextIndex = upper_bound(grid.begin(), grid.end(), vec) - grid.begin();
        int take = grid[i][2] + state(nextIndex, jobs+1);
        int notTake = state(i+1, jobs);
        return dp[i][jobs] = max(take, notTake);
    }

    // static bool comp(vector<int>& a, vector<int>& b) {
    //     return a[1] < b[1];
    // }

    int maxTwoEvents(vector<vector<int>>& events) {
        int ans = 0;
        int n = events.size();

        // // O(n^2)
        // sort(events.begin(), events.end(), comp);
        // for(int i=0; i<n; i++) {
        //     int e1 = events[i][1]; 
        //     int c1 = events[i][2];
        //     ans = max(ans, c1);

        //     for(int j=i+1; j<n; j++) {
        //         int s2 = events[j][0];
        //         int c2 = events[j][2];
        //         if(s2 > e1) {
        //             int curSum = c1 + c2;
        //             ans = max(ans, curSum);
        //         }
        //     }
        // }

        /*
            Input: events = [[1,3,2],[4,5,2],[2,4,3]]
            Output: 4

            after sort [[1,3,2],[2,4,3],[4,5,2]]

            i = 0, empty minHeap, maxSoFar = 0, ans = 2, now(push[1,3,2])
            i = 1, {3,1,2}, maxSoFar = 0, ans = 3, now(push[2,4,3])
            i = 2, {3,1,2},{4,2,1}, maxSoFar = 2, ans = 4, now(pop[3,2,1], push[4,5,2])
            i = 3, loop ends
        */
        // // O(n * logn)
        // sort(events.begin(), events.end());
        // int maxSoFar = 0;
        // priority_queue<vector<int>> minHeap; // sort by ending time
        // for(int i=0; i<n; i++) {
        //     int curStart = events[i][0];
        //     int curEnd = events[i][1];
        //     int curCost = events[i][2]; 
        //     while(!minHeap.empty() && curStart > (-minHeap.top()[0])) {
        //         maxSoFar = max(maxSoFar, minHeap.top()[2]);
        //         minHeap.pop();
        //     }
        //    ans = max(ans, curCost + maxSoFar);
        //    minHeap.push({-curEnd, curStart, curCost});
        // }

        // O(n * logn) dp + bs
        int k = 2;
        dp.resize(n+1, vector<int>(k+1, -1));
        grid = events;
        N = n;
        K = k;
        sort(grid.begin(), grid.end()); // make sure to sort to apply binary search
        ans = state(0, 0);

        return ans;
    }
};