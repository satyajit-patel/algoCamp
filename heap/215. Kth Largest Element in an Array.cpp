class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> minHeap;
        for(auto& it: nums) {
            minHeap.push(it * -1);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top() * -1;
    }
};