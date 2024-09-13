#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define endl "\n"
#define vvi vector<vector<int>>

// ---------------------------------------------------------------------

void solve() {
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        string x, s; cin>>x>>s;
        
        bool found = false;
        for(int opr=0; opr<=5; opr++) {
            // cout << x << endl;
            if(x.find(s) != -1) {
                found = true;
                cout << opr << endl;
                break;
            }
            x += x;
        }
        
        if(!found) {
            cout << -1 << endl; 
        }
    }
}

// ---------------------------------------------------------------------

int main() {
    solve();
    return 0;
}
