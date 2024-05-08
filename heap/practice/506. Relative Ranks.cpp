/*
        Input: score = [10,3,8,9,4]
        Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
    */

    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> maxHeap;
        for(auto& it: score) {
            maxHeap.push(it);
        }
        map<int, int> mp;
        int rank = 1;
        while(!maxHeap.empty()) {
            int ele = maxHeap.top();
            maxHeap.pop();
            mp[ele] = rank++;   
        }
        vector<string> ans(score.size());
        for(int i=0; i<score.size(); i++) {
            int x = mp[score[i]];
            if(x == 1) {
                ans[i] = "Gold Medal";
            } else if(x == 2) {
                ans[i] = "Silver Medal";
            } else if(x == 3) {
                ans[i] = "Bronze Medal";
            } else {
                ans[i] = to_string(x);
            }
        }
        return ans; 
    }