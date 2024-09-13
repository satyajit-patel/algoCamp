#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/strings/STRINGS/problems/ADDONE

void solve() {
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        
        vector<int> arr;
        for(auto& it: s) {
            arr.push_back(it - '0');
        }
        
        // for(auto& it: arr) {
        //     cout<<it;
        // }
        // cout<<endl;
        
        int carry = 0;
        vector<int> ans;
        int n = arr.size();
        int sum = arr[n-1] + carry + 1;
        int lastDigit = sum % 10;
        carry = sum / 10;
        ans.push_back(lastDigit);
        for(int i=n-2; i>=0; i--) {
            sum = carry + arr[i];
            lastDigit = sum % 10;
            carry = sum / 10;
            ans.push_back(lastDigit);
        }
        while(carry) {
            lastDigit = carry % 10;
            carry = carry / 10;
            ans.push_back(lastDigit);
        }
        reverse(ans.begin(), ans.end());
        for(auto& it: ans) {
            cout<<it;
        }
        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}