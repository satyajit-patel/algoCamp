class Solution {
public:
    vector<int> max_of_subarrays(int *arr, int n, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0,j=0; i<n && j<n; j++) {
            while(!dq.empty() && arr[j]>dq.back()) {
                dq.pop_back(); // jaldi wahan se hatto
            }
            dq.push_back(arr[j]);
            
            if(j-i+1 == k) {
                ans.push_back(dq.front());
                if(dq.front() == arr[i]) {
                    dq.pop_front();
                }
                i++;
            }
        }
        return ans;
    }
};