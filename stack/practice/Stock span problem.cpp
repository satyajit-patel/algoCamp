class Solution {
public:
    vector<int> getPge(int* arr, int n){
        vector<int> output(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++) {
            // work
            while(!st.empty() && arr[i] >= arr[st.top()]) {
                st.pop();
            }
            
            // update
            if(!st.empty()) {
                output[i] = st.top();
            }
            
            // insert
            st.push(i);
        }
        return output;
    }

    vector<int> calculateSpan(int price[], int n) {
        vector<int> pge = getPge(price, n);
        vector<int> ans;
        ans.push_back(1);
        for(int i=1; i<n; i++) {
            ans.push_back(i - pge[i]);
        }
        return ans;
    }
};