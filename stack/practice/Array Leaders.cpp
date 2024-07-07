class Solution {
public:
    /*
        https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
        Input: n = 6, arr[] = {16,17,4,3,5,2}
        Output: 17 5 2
        Explanation: 
        Note that there is nothing greater on the right side of 17, 5 and, 2.
    */

    vector<int> leaders(int n, int arr[]) {
        vector<int> ans;
        stack<int> st;
        
        st.push(arr[n-1]);
        for(int i=n-2; i>=0; i--) {
            if(arr[i] >= st.top()) {
                st.push(arr[i]);
            }
        }
        while(!st.empty()) {
            int x = st.top();
            st.pop();
            ans.push_back(x);
        }
        return ans;
    }
};
