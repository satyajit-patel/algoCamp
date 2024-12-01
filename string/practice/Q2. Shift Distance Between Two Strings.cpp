// https://leetcode.com/contest/biweekly-contest-144/problems/shift-distance-between-two-strings/
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& prevCost) {
        long long ans = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == t[i]) {
                continue;
            }
            
            int s1 = s[i] - 'a';
            int t1 = t[i] - 'a';

            long long nc = 0;
            while(s1 != t1) {
                nc += nextCost[s1];
                s1 = (s1 + 1) % 26;
            }
            s1 = s[i] - 'a';
            long long pc = 0;
            while(s1 != t1) {
                pc += prevCost[s1];
                s1 = (s1 - 1 + 26) % 26;
            }
            ans += min(nc, pc);
        }
        return ans;
    }
};