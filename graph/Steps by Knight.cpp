// https://www.geeksforgeeks.org/problems/steps-by-knight5927/1
class Solution {
public:
    /*
        Knight moves 8 direction at a time
        [.][#][.][#][.]
        [#][.][.][.][#]
        [.][.][K][.][.]
        [#][.][.][.][#]
        [.][#][.][#][.]
    */
    // LURD
    int dx[8] = {-1,+1, -2,-2, -1,+1, +2,+2};
    int dy[8] = {-2,-2, -1,+1, +2,+2, -1,+1};

    bool isvalid(int i, int j, int N) {
        return i>=0 && i<N && j>=0 && j<N;
    }

	int minStepToReachTarget(vector<int>& s,vector<int>& d,int N) {
	    int x1 = s[0]-1;
	    int y1 = s[1]-1;
	    
	    int x2 = d[0]-1;
	    int y2 = d[1]-1;
	    
	    vector<vector<int>> vis(N, vector<int>(N, 0));
	    vis[x1][y1] = 1;
	    queue<pair<int, pair<int, int>>> q;
	    q.push({0, {x1, y1}});
	    
	    while(!q.empty()) {
	        auto it = q.front();
	        q.pop();
	        int step = it.first;
	        int i = it.second.first;
	        int j = it.second.second;
	        
	        if(i == x2 && j == y2) {
	            return step;
	        }
	        
	        for(int ind=0; ind<8; ind++) {
	            int ni = i + dx[ind];
	            int nj = j + dy[ind];
	            if(isvalid(ni, nj, N) && !vis[ni][nj]) {
	                vis[ni][nj] = 1;
	                q.push({step+1, {ni, nj}});
	            }
	        }
	    }
	    
	    return -1;
	}
};