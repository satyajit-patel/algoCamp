 /*
        Constraints:
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 20
        grid[i][j] is either 0 or 1.

        f(n) = O(n^8)
    */

    int binaryToDecimal(auto& row) {
        // string s = "";
        // for(auto& it: row) {
        //     s += to_string(it);
        // }
        // bitset<32> b(s);
        // return b.to_ulong();

        // or

        int ans = 0;
        int n = row.size();
        for(int i=0; i<n; i++) { // O(n)
            if(row[i] == 1) {
                ans += pow(2, n-1-i); // O(log n)
            }
        }
        return ans;
    }

    void toggleTheColumn(auto& grid, int j, int n) {
        for(int i=0; i<n; i++) {
            grid[i][j] = (grid[i][j] == 1) ? 0 : 1;
        }
    }

    bool isContainMoreZero(auto& grid, int j, int n) {
        int ones = 0;
        int zeros = 0;
        for(int i=0; i<n; i++) {
            if(grid[i][j] == 1) {
                ones++;
            } else {
                zeros++;
            }
        }
        return zeros > ones;
    }

    void toggleTheRow(auto& grid, int i, int m) {
        for(int j=0; j<m; j++) {
            grid[i][j] = (grid[i][j] == 1) ? 0 : 1;
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // checking row
        for(int i=0; i<n; i++) { // O(n)
            if(grid[i][0] != 1) {
                toggleTheRow(grid, i, m); // O(1) as we are not doing for each row
            }
        }
        // checking column
        for(int j=0; j<m; j++) { // O(n)
            if(isContainMoreZero(grid, j, n)) { 
                toggleTheColumn(grid, j, n); // O(1) as we are not doing for each column
            }
        }
        int ans = 0;
        for(auto& row: grid) { // O(n)
            ans += binaryToDecimal(row); // O(n + logn) as we are doing for each row
        }
        // n + N + (n^2 + logn) = O(n^2)
        return ans;
    }