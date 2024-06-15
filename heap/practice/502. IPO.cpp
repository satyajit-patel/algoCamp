class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = {capital[i], profits[i]};
        }
        sort(arr.begin(), arr.end());

        int i = 0;
        priority_queue<int, vector<int>> maxHeap;
        while(k--) {
            while(i < n && arr[i].first <= w) {
                maxHeap.push(arr[i].second);
                i++;
            }
            
            if(maxHeap.empty()) {
                break;
            }
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};