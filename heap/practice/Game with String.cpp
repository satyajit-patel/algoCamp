/*
        Input: 
        s = abccc, k = 1
        Output: 
        6
        Explaination:
        We remove c to get the value as 1^2 + 1^2 + 2^2
        
        Constraints:
        0 ≤ k ≤ |string length| ≤ 10^5
        
        f(n) = O(nlogn)
    */

    int minValue(string s, int k){
        map<char, int> map;
        for(auto& it: s) {
            map[it]++;
        }
        priority_queue<int> pq;
        for(auto& it: map) {
            pq.push(it.second);
        }
        
        while(k--) {
            int freq = pq.top();
            pq.pop();
            
            freq--;
            if(freq) {
                pq.push(freq);
            }
        }
        
        int ans = 0;
        while(!pq.empty()) {
            int ele = pq.top();
            pq.pop();
            ans += (ele * ele);
        }
        return ans;
    }