// https://leetcode.com/contest/biweekly-contest-136/problems/find-the-number-of-winning-players/description/
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int winner = 0;

        map<int, map<int, int>> mp;
        for(auto& row: pick) {
            int person = row[0];
            int ballType = row[1];
            mp[person][ballType]++;
        }

        for(int playerNum=0; playerNum<n; playerNum++) {
            if(mp.count(playerNum)) {
                auto mpp = mp[playerNum];
                bool isWin = false;
                for(auto& it: mpp) {
                    int sameBallFreq = it.second;
                    if(sameBallFreq > playerNum) {
                        isWin = true;
                        break;
                    }
                }
                if(isWin) {
                    winner++;
                }
            }
        }

        return winner;
    }
};