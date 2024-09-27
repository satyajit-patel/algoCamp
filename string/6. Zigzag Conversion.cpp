class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) {
            return s;
        }

        /*
            input-> "PAYPALISHIRING"

            0->[P][-][-][-][A][-][-][-][H][-][-][-][N][-]
            1->[-][A][-][P][-][L][-][S][-][I][-][I][-][G]
            2->[-][-][Y][-][-][-][I][-][-][-][R][-][-][-]
            
            output-> PAHN->APLSIIG->YIR
            012->10->12->10->12->10->1
            pattern
            01210121012101
            it's like
            0 1 2 -> 2 1 0 -> 0 1 2 -> 2 1 0
        */

        string adj[n];
        int curRow = 0;
        int mod = 1;
        for(auto& it: s) {
            adj[curRow].push_back(it);
            if(curRow == 0) {
                mod = 1;
            }
            if(curRow == n-1) {
                mod = -1;
            }
            curRow += mod;
        }

        s.clear();
        for(int i=0; i<n; i++) {
            s += (adj[i]);
        }
        return s;
    }
};