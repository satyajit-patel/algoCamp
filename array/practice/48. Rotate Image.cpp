class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int n = matrix.size();
        for(int i=0; i<n; i++) {
            vector<int> temp;
            for(int j=n-1; j>=0; j--) {
                temp.push_back(matrix[j][i]);
            }
            ans.push_back(temp);
        }
        matrix = ans;
    }
};