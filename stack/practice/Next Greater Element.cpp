
class Solution {
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n) {
	// NGE
        // NSE = sign change of NGE
        // PGE = reverse arr + NGE
        // PSE = reverse arr + NSE

        vector<long long> nge(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            // work
            while(!st.empty() && arr[i] >= arr[st.top()]) {
                st.pop();
            }
            
            // update
            if(!st.empty()) {
                nge[i] = arr[st.top()];
            }
            
            // insert
            st.push(i);
        }
        return nge;
    }
};