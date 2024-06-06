#include<bits/stdc++.h>
using namespace std;

// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/cannibal-characters-d30e8a5f/

int Minimum_Operations (int n, string s) {
   /*
        babbaaa
        a -> 4
        b -> 3

        ans
        =>(4/2) + (3/2)
        => 2 + 1
        => 3
   */
    
    map<char, int> mp;
    for(auto& it: s) {
        mp[it]++;
    }
    int ans = 0;
    for(auto& it: mp) {
        ans += (it.second/2);
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int out_;
        out_ = Minimum_Operations(n, s);
        cout << out_;
        cout << "\n";
    }
}