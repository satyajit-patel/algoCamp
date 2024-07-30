class Solution {
public:
    void floydWarshal(vector<vector<long long>>& adjMat) {
        // O(1)
        for(int k=0; k<26; k++) {
            for(int i=0; i<26; i++) {
                for(int j=0; j<26; j++) {
                    adjMat[i][j] = std::min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans = 0; 
        int n = source.size();
        int m = original.size();

        vector<vector<long long>> adjMat(26, vector<long long>(26, INT_MAX));
        for(int x=0; x<m; x++) {
            int i = original[x] - 'a';
            int j = changed[x] - 'a';
            int w = cost[x];
            // directed graph
            adjMat[i][j] = std::min(adjMat[i][j], (long long)w); // as there could be duplicates
        }
        floydWarshal(adjMat);

        for(int x=0; x<n; x++) {
            if(source[x] == target[x]) {
                continue;
            }

            int i = source[x] - 'a';
            int j = target[x] - 'a';
            int shortestDist = adjMat[i][j];
            if(shortestDist == INT_MAX) {
                return -1; // no path exist
            }
            ans += shortestDist;
        }

        return ans;
    }
};