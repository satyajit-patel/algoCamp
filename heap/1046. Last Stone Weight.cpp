class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap(stones.begin(), stones.end());
        while(maxHeap.size() >= 2) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();

            if(x != y) {
                maxHeap.push(std::abs(x - y));
            }
        }

        if(maxHeap.empty()) {
            return 0;
        }
        return maxHeap.top();
    }
};