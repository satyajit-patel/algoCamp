class Solution {
public:
    // void ab(string& s, int x, int& ans) {
    //     while(1) {
    //         int index = s.find("ab");
    //         if(index != -1) {
    //             ans += x;
    //             s.erase(index, 2);
    //             continue;
    //         }
    //         return;
    //     }
    // }

    // void ba(string& s, int y, int& ans) {
    //     // O(n^2)
    //     while(1) { // O(n)
    //         int index = s.find("ba"); // O(n)
    //         if(index != -1) {
    //             ans += y;
    //             s.erase(index, 2); // O(n)
    //             continue;
    //         }
    //         return;
    //     }
    // }

    // int TLE(string& s, int x, int y) {
    //     int ans = 0;

    //     if(x > y) {
    //         ab(s, x, ans);
    //         ba(s, y, ans);
    //     } else {
    //         ba(s, y, ans);
    //         ab(s, x, ans);
    //     }

    //     return ans;
    // }

    int optimal(string& s, int x, int y) {
        int ans = 0;

        // O(n) + O((n/2log(n/2)) + O(n/2) = O(nlogn)
        if(x > y) {
            stack<char> st;
            for(auto& it: s) {
                if(!st.empty() && st.top() == 'a' && it == 'b') {
                    st.pop();
                    ans += x;
                } else {
                    st.push(it);
                }
            }

            string temp = "";
            while(!st.empty()) {
                temp += st.top();
                st.pop();
            }
            std::reverse(temp.begin(), temp.end());

            for(auto& it: temp) {
                if(!st.empty() && st.top() == 'b' && it == 'a') {
                    st.pop();
                    ans += y;
                } else {
                    st.push(it);
                }
            }
        } else {
            // cout<<s<<endl;
            stack<char> st;
            for(auto& it: s) {
                if(!st.empty() && st.top() == 'b' && it == 'a') {
                    st.pop();
                    ans += y;
                } else {
                    st.push(it);
                }
            }

            string temp = "";
            while(!st.empty()) {
                temp += st.top();
                st.pop();
            }
            std::reverse(temp.begin(), temp.end());
            s = temp;
            // cout<<s<<endl;

            for(auto& it: s) {
                if(!st.empty() && st.top() == 'a' && it == 'b') {
                    st.pop();
                    ans += x;
                } else {
                    st.push(it);
                }
            }

            // temp = "";
            // while(!st.empty()) {
            //     temp += st.top();
            //     st.pop();
            // }
            // std::reverse(temp.begin(), temp.end());
            // s = temp;
            // cout<<s<<endl;
        }

        return ans;
    }

    int maximumGain(string& s, int x, int y) {
        // return TLE(s, x, y);
        return optimal(s, x, y);
    }
};