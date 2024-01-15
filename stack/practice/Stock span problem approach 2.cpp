class Solution {
public:
    vector<int> getNge(vector<pair<int, int>>& arr, int n){
        vector<int> output(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            // work
            while(!st.empty() && arr[i].first >= arr[st.top()].first) {
                st.pop();
            }
            
            // update
            if(!st.empty()) {
                output[i] = arr[st.top()].second;
            }
            
            // insert
            st.push(i);
        }
        return output;
    }

    vector<int> calculateSpan(int price[], int n) {
        vector<pair<int, int>> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = {price[i], i};
        }
        // pge = rev arr + nge
        reverse(arr.begin(), arr.end());
        vector<int> pge = getNge(arr, n);
        reverse(pge.begin(), pge.end());
        
        vector<int> ans;
        ans.push_back(1);
        for(int i=1; i<n; i++) {
            ans.push_back(i - pge[i]);
        }
        return ans;
    }
};