class Solution{
public:
    int isValid(vector<vector<int>> mat) {
        // arrays of set
        set<int> row[9], col[9];
        // 2d arrays of set
        set<int> smallMat[3][3];
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                int num = mat[i][j];
                if(num == 0) {
                    continue;
                }
                
                if(row[i].count(num)) {
                    return false;
                }
                if(col[j].count(num)) {
                    return false;
                }
                if(smallMat[i/3][j/3].count(num)) {
                    return false;
                }
                
                row[i].insert(num);
                col[j].insert(num);
                smallMat[i/3][j/3].insert(num);
            }
        }
        return true;
    }
};