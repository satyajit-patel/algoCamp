class Solution {
public:
    vector<int> getNse(vector<int>& arr, int n){
        vector<int> nse(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            // work
            // for nse just the sign change of nge
            while(!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            
            // update
            if(!st.empty()) {
                nse[i] = arr[st.top()];
            }
            
            // insert
            st.push(i);
        }
        return nse;
    }

    vector<int> leftSmaller(int n, int a[]) {
        // PSE = rev arr + nse
        vector<int> arr;
        for(int i=0; i<n; i++) {
            arr.push_back(a[i]);
        }
        reverse(arr.begin(), arr.end());
        vector<int> pse = getNse(arr, n);
        reverse(pse.begin(), pse.end());
        return pse;
    }
};