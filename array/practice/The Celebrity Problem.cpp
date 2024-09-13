// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int cele = -1;
        for(int i=0; i<mat.size(); i++) {
            set<int> st(mat[i].begin(), mat[i].end());
            int l = *st.begin();
            int r = *--st.end();
            if(l == 0 && r == 0) {
                cele = i;
                break;
            }
        }
        // if there is no celebrity return -1
        if(cele == -1) {
            return -1;
        }
        // make sure all know the celebrity
        for(int i=0; i<mat.size(); i++) {
            if(i != cele) {
                if(mat[i][cele] != 1) {
                    return -1;
                }
            }
        }
        return cele;
    }
};