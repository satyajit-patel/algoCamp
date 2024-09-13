
#include <bits/stdc++.h>
using namespace std;
// https://www.codechef.com/practice/course/strings/STRINGS/problems/DNASTORAGE
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        // 0011 => AG
        string ans = "";
        for(int i=0; i<n; i+=2) {
            string temp = s.substr(i, 2);
            if(temp == "00") {
                ans += 'A';
            } else if(temp == "11") {
                ans += 'G';
            } else if(temp == "10") {
                ans += 'C';
            } else if(temp == "01") {
                ans += 'T';
            }
        }
        cout<<ans<<endl;
    }

}
