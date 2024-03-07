#include<bits/stdc++.h>
using namespace std;

/* 
    https://www.codechef.com/problems/SWAPUNITE
    4               
    aba
    abab
    baabba
    ppssppss
    
    0
    1
    1
    2
*/

void solve() {
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        
        int ans = INT_MAX;
        map<char, int> map;
        for(auto& it: s) {
            map[it]++;
        }
        
        for(auto& it: map) {
            char ch = it.first;
            int freq = it.second;
            
            // sliding window
            int l = 0;
            int r = freq-1;
            int c = 0;
            
            for(int i=l; i<=r; i++) {
                if(s[i] == ch) {
                    c++;
                }
            }
            ans = min(ans, freq - c);
            while(r < s.size()) {
                if(s[l] == ch) {
                    c--;
                }
                l++;
                
                if(r + 1 < s.size() && s[r+1] == ch) {
                    c++;
                }
                r++;
                ans = min(ans, freq - c);
            }
            
        }
        cout<<ans<<"\n";
    }
}

int main() {
    solve();
    return 0;
}