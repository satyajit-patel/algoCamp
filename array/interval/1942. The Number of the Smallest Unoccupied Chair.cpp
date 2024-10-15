class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<vector<int>> grid(n);
        for(int i=0; i<n; i++) {
            int inTime = times[i][0];
            int outTime = times[i][1];
            int friendNumber = i;
            grid[i] = {inTime, outTime, friendNumber};
        }
        sort(grid.begin(), grid.end());
        vector<int> chairs(n, -1); // i.e all are availabe to sit
        for(int i=0; i<n; i++) {
            int inTime = grid[i][0];
            int outTime = grid[i][1];
            int friendNumber = grid[i][2];
            for(int chairNumber=0; chairNumber<n; chairNumber++) { // scope to improvise
                if(chairs[chairNumber] <= inTime) {
                    chairs[chairNumber] = outTime;
                    if(friendNumber == targetFriend) {
                        return chairNumber;
                    }
                    break;
                }
            }
        }
        return n; // bring your own fucking chair
    }
};