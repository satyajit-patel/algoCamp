
class Solution{
public:
    vector<int> getNse(vector<int>& arr, int n){
        vector<int> nge(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            // work
            // for nse just the sign change of nge
            while(!st.empty() && arr[i] <= arr[st.top()]) {
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

    vector<int> help_classmate(vector<int>& arr, int n) { 
        vector<int> nse = getNse(arr, n);
        return nse;
    } 
};