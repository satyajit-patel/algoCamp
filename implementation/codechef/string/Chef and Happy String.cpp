#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/strings/STRINGS/problems/HAPPYSTR

bool isvowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return true;
    }
    return false;
}

bool allVowel(char ch1 , char ch2, char ch3) {
    return isvowel(ch1) && isvowel(ch2) && isvowel(ch3);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        // your code goes here
        
        bool found = false;
        for(int i=2; i<s.size(); i++) {
            if(allVowel(s[i], s[i-1], s[i-2])) {
                found = true;
                break;
            }
        }
        if(found) {
            cout<<"Happy\n";
        } else {
            cout<<"Sad\n";
        }
    }

}
