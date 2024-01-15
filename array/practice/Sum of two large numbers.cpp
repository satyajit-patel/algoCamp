class Solution {
public:
    vector<int> f(vector<int>& x, vector<int>& y) {
        vector<int> ans;
        std::reverse(x.begin(), x.end());
        std::reverse(y.begin(), y.end());
        int size = std::min(x.size(), y.size());
        int carry = 0;
        for(int i=0; i<size; i++) {
            int value = x[i] + y[i] + carry;
            int digit = value % 10;
            carry = value / 10;
            ans.push_back(digit);
        }
        if(x.size() > size) {
            for(int i=size; i<x.size(); i++) {
                int value = x[i] + carry;
                int digit = value % 10;
                carry = value / 10;
                ans.push_back(digit);
            }
        }
        if(y.size() > size) {
            for(int i=size; i<y.size(); i++) {
                int value = y[i] + carry;
                int digit = value % 10;
                carry = value / 10;
                ans.push_back(digit);
            }
        }
        while(carry) {
            int digit = carry % 10;
            carry /= 10;
            ans.push_back(digit);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string findSum(string& X, string& Y) {
        vector<int> x, y;
        for(auto& it: X) {
            x.push_back(it - '0');
        }
        for(auto& it: Y) {
            y.push_back(it - '0');
        }
        vector<int> ans = f(x, y);
        string result = "";
        bool isAllZero = true;
        for(auto& it: ans) {
            if(it != 0) {
                isAllZero = false;
            }
            result += (it + '0');
        }
        if(isAllZero == true) {
            return "0";
        }
        int i = result.find_first_not_of('0');
        return result.substr(i);
    }
};