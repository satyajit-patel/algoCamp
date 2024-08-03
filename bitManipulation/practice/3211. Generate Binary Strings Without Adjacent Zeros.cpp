class Solution {
public:
    void state(int n, vector<string>& temp, string s) {
        // base case
        if(s.size() == n) {
            temp.push_back(s);
            return;
        }

        // transition
        state(n, temp, s+'0');
        state(n, temp, s+'1');
    }

    vector<string> validStrings(int n) {
        vector<string> ans;

        // SUPER SET O(2^n)
        int size = 1 << n;
        vector<string> temp;
        for(int ele=0; ele<size; ele++) {
            string s(n, '0');
            for(int i=0; i<n; i++) {
                if(ele & (1 << i)) {
                    s[i] = '1';
                }
            }
            temp.push_back(s);
        }

        // vector<string> temp;
        // state(n, temp, ""); // RECURSION O(2^n)

        // for(auto& it: temp) {
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        for(auto& it: temp) {
            int init = 0;
            string s = it;
            bool flag = true;
            // sliding window check
            for(int i=0; i<s.size(); i++) {
                if(i-init+1 == 2) {
                    if(s[init] != '1' && s[init+1] != '1') {
                        flag = false;
                        break;
                    }
                    init++;
                } 
            }
            if(flag) {
                ans.push_back(s);
            }
        }

        return ans;
    }
};