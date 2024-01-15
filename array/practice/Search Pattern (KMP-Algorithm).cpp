class Solution {
public:
    vector<int> getZ(string s) {
        /*
            in string S at each position 
            gives the length of longest substring
            starting from position i
            which is also a prefix of the string S
            
            example :-
            S = g  e  e  k  ?  g  e  e  k s f  o  r  g  e  e  k  s
               18  0  0  0  0  4  0  0  0 0 0  0  0  4  0  0  0  0
               here
               g == 4 because
               from starting only 4 char are matching with prefix od S
        */
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    
    vector<int> search(string pat, string txt) {
        string extra = pat + '?';
        string newTxt = extra + txt;
        vector<int> z = getZ(newTxt);
        vector<int> ans;
        for(int i=0; i<z.size(); i++) {
            if(z[i] == pat.size()) {
                int index = (i - extra.size()) + 1;
                ans.push_back(index);
            }
        }
        return ans;
    }
};