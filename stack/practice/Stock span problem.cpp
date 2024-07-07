// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
class Solution {
public:
    vector<int> calculateSpan(int price[], int n) {
        vector<int> span(n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            // maintain monotonic increasing
            while(!st.empty() && price[i] >= price[st.top()]) {
                st.pop();
            }
            
            if(!st.empty()) {
                span[i] = i - st.top();
            } else {
                span[i] = i + 1;
            }
            
            st.push(i);
        }
        return span;
    }
};
