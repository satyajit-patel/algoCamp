// https://leetcode.com/contest/weekly-contest-409/problems/design-neighbor-sum-service/description/
class neighborSum {
private:
    vector<vector<int>> mat;
    int n;
    int m;
public:
    bool isvalid(int i, int j) {
        return i>=0 && i<n && j>=0 && j<m;
    }

    pair<int, int> findIndex(int target) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == target) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    neighborSum(vector<vector<int>>& grid) {
        mat.clear();
        mat = grid;
        n = mat.size();
        m = mat[0].size();
    }
    
    int adjacentSum(int value) {
        int ans = 0;
        
        pair<int, int> p = findIndex(value);
        int i = p.first;
        int j = p.second;
        if(i == -1 && j == -1) {
            return ans;
        }

        if(isvalid(i, j-1)) { // left
            ans += mat[i][j-1];
        }
        if(isvalid(i-1, j)) { // up
            ans += mat[i-1][j];
        }
        if(isvalid(i, j+1)) { // right
            ans += mat[i][j+1];
        }
        if(isvalid(i+1, j)) { // down
            ans += mat[i+1][j];
        }

        return ans;
    }
    
    int diagonalSum(int value) {

        int ans = 0;
        
        pair<int, int> p = findIndex(value);
        int i = p.first;
        int j = p.second;
        if(i == -1 && j == -1) {
            return ans;
        }

        if(isvalid(i-1, j-1)) { // left up
            ans += mat[i-1][j-1];
        }
        if(isvalid(i-1, j+1)) { // right up
            ans += mat[i-1][j+1];
        }
        if(isvalid(i+1, j+1)) { // right down
            ans += mat[i+1][j+1];
        }
        if(isvalid(i+1, j-1)) { // left down
            ans += mat[i+1][j-1];
        }
        return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */