/*
        n = 9
        acdcdacdc
        Output:
        "acdc"
        
        11
        abaabbbbbaa
        output:
        baa
        
        Constraints:
        1 <= n <= 10^3
    */
  
    string longestSubstring(string s, int n) {
        // string result = "-1"; // here result.size() == 2(- is also a char)
        string result = "";
        
        for(int i=0; i<n; i++) {
            string ans = "";
            for(int j=i; j<n; j++) {
                ans += s[j];
                string temp = s.substr(j+1);
                if(temp.find(ans) == string::npos) {
                    ans.pop_back();
                    break;
                }
            }
            // cout<<ans<<"->\n";
            // cout<<ans.size()<<" "<<result.size()<<"->\n";
            if(ans.size() > result.size()) {
                // cout<<"hi\n";
                result = ans;
            }
            // cout<<result<<"->\n";
        }
        
        if(result.empty()) {
            return "-1";
        }
        return result;
    }