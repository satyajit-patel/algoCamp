class Solution {
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ans;
        deque<int> q;
        int i = 0, j = 0;
        while(i<n && j<n) {
            while(!q.empty() && arr[j] > q.back()) {
                q.pop_back();
            }
            q.push_back(arr[j]);
            
            if(j-i+1 < k) {
                j++;
            } else if(j-i+1 == k) {
                ans.push_back(q.front());
                if(arr[i] == q.front()) {
                    q.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};