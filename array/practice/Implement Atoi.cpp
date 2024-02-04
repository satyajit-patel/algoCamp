#include<bits/stdc++.h>
class Solution {
public:
    int atoi(string& s) {
        // bool isNagative = false;
        // if(s[0] == '-') {
        //     isNagative = true;
        // }
        
        // string ans = "";
        // for(int i=0; i<s.size(); i++) {
        //     if(s[i] != '-' && !(s[i]>='0' && s[i]<='9')) {
        //         return -1;
        //     }
        //     if(s[i] == '-' && i != 0) {
        //         return -1;
        //     }
        //     if(s[i] != '-') {
        //         ans += s[i];   
        //     }
        // }
        // // cout<<"\n"<<ans<<"->\n";
        // int res = 0;
        // res = stoi(ans);
        // if(isNagative) {
        //     res *= -1;
        // }
        // return res;
        
        
        int ans = 0, start = 0;
        if(s[0] == '-'){
            start = 1;
        }
        for(int i=start; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9'){
                ans = ans * 10 + (s[i] - '0');
            } else {
                return -1;
            }
        }
        if(s[0] == '-'){
            return ans *= -1;
        }
        return ans;
    }
};