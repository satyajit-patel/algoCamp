class Solution {
public:
    string minWindow(string& s, string& t) {
        string ans = "";
        int start = -1;
        int mini = INT_MAX;
        int n = s.size();
        int m = t.size();

        // // O(n^2) TLE
        // for(int i=0; i<n; i++) { // O(n)
        //     map<char, int> mp;
        //     for(auto& it: t) { // O(m)
        //         mp[it]++;
        //     }
        //     int count = 0;
        //     for(int j=i; j<n; j++) { // O(n)
        //         if(mp[s[j]] > 0) { // means got one
        //             count++;
        //         }
        //         mp[s[j]]--;
        //         if(count == m) {
        //             if(j-i+1 < mini) {
        //                 mini = j-i+1;
        //                 start = i;
        //                 break;
        //             }
        //         }
        //     }
        // }

        // sliding window
        map<char, int> mp;
        for(auto& it: t) {
            mp[it]++;
        }
        int init = 0;
        int count = 0;
        // O(n) + O(n) = O(n)
        for(int i=0; i<n; i++) { // O(n)
            if(mp[s[i]] > 0) {
                count++;
            }
            mp[s[i]]--;
            while(count == m) { // O(n) at worst once
                if(i-init+1 < mini) {
                    mini = i-init+1;
                    start = init;
                }
                mp[s[init]]++;
                if(mp[s[init]] > 0) {
                    count--;
                }
                init++; 
            }
        }

        if(mini != INT_MAX) {
            ans = s.substr(start, mini);
        }

        return ans;
    }
};