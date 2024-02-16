/*
    Input:
    S = "geeksforgeeks"
    Output: 7
    Explanation: "eksforg" is the longest 
    substring with all distinct characters.
*/

int longestSubstrDistinctChars (string S) {
    int ans = 0;
    map<char, int> map;
    for(int i=0,init=0; i<S.size(); i++) {
        if(map.find(S[i]) != map.end()) {
            init = max(init, map[S[i]]);
        }
        ans = max(ans, i-init+1);
        map[S[i]] = i+1;
    }
    return ans;
}