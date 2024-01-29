class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // int i=0, j = arr.size()-1;
        // while(j-i+1 > k) {
        //     int leftDiff = abs(arr[i] - x);
        //     int rightDiff = abs(arr[j] - x);
        //     if(leftDiff <= rightDiff) {
        //         j--;
        //     } else {
        //         i++;
        //     }
        // }
        // vector<int> ans;
        // for(i; i<=j; i++) {
        //     ans.push_back(arr[i]);
        // }
        // return ans;

        priority_queue<pair<int, int>> pq;
        for(auto& it: arr) {
            pq.push({abs(it - x), it});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};