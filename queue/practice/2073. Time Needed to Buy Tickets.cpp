/*
        Input: tickets = [5,1,1,1], k = 0
        Output: 8

        n == tickets.length
        1 <= n <= 100
        1 <= tickets[i] <= 100
        0 <= k < n
    */

    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            q.push({i, tickets[i]});
        }

        int ans = INT_MIN;
        int time = 0;
        while(!q.empty()) {
            int index = q.front().first;
            int element = q.front().second;
            q.pop();

            time++;
            element--;
            if(element) {
                q.push({index, element});
            }
            if(index == k) {
                ans = max(ans, time);
            }          
        }

        return ans;
    }