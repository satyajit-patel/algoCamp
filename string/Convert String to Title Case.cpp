#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/strings/STRINGS/problems/TITLECASE?tab=statement

bool allCapital(string& word) {
    for(int i=0; i<word.size(); i++) {
        if(islower(word[i])) {
            return false;
        }
    }
    return true;
}

void solve() {
    int t; cin>>t;
    t++;
    while(t--) {
        string s; getline(cin, s);
        
        string ans = "";
        stringstream ss(s);
        while(ss.good()) {
            string word;
            getline(ss, word, ' ');
            // cout<<word<<" ";
            if(allCapital(word)) {
                ans += word + " ";
            } else {
                for(int i=0; i<word.size(); i++) {
                    if(i == 0) {
                        word[i] = toupper(word[i]);
                    } else {
                        word[i] = tolower(word[i]);
                    }
                }
                ans += word + " ";
            }
        }
        
        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}