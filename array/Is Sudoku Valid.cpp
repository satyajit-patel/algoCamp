int isValid(vector<vector<int>> mat){
        set<int> row[9], col[9], subMatrix[3][3];
        int emptyBlock = 0;
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                int ele = mat[i][j];
                if(ele == emptyBlock) {
                    continue;
                }
                if(row[i].find(ele) != row[i].end()) {
                    return 0;
                }
                if(col[j].find(ele) != col[j].end()) {
                    return 0;
                }
                if(subMatrix[i/3][j/3].find(ele) != subMatrix[i/3][j/3].end()) {
                    return 0;
                }
                
                row[i].insert(ele);
                col[j].insert(ele);
                subMatrix[i/3][j/3].insert(ele);
            }
        }
        return 1;
    }