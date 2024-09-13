class Solution {
public:
    string removeDuplicates(string s, int k) {
        // // TLE
        // set<char> st(s.begin(), s.end());
        // while(1) {
        //     bool flag = true;
        //     for(auto& it: st) {
        //         string pat(k, it);
        //         while(1) {
        //             int index = s.find(pat);
        //             if(index == -1) {
        //                 break;
        //             }
        //             s.erase(index, k);
        //             flag = false;
        //         }
        //     }
        //     if(flag) {
        //         break;
        //     }
        // }
        // return s;

        if(s.size() < k) {
            return s;
        }
        stack<pair<char, int>> st;
        for(auto& it: s) {
            if(st.empty() || st.top().first != it) {
                st.push({it, 1});
            } else {
                st.top().second++;
            }
            if(st.top().second == k) {
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty()) {
            string temp(st.top().second, st.top().first);
            st.pop();
            ans = temp + ans;
        }
        return ans;
    }
};