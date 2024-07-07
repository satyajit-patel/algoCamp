#include<bits/stdc++.h>
using namespace std;
/*
    https://www.codechef.com/START124D/problems/BINPARITY
    
*/ 
void solve() {
    int tc; cin>>tc;
    while(tc--) {
        int n; cin>>n;
        
        int num_parity = 0;
        
        // bitset<32> b(n);
        // num_parity = b.count();
        
        // for(int i=0; i<32; i++) {
        //     if(n & (1 << i)) {
        //         num_parity++;
        //     }
        // }
        
        while(n) {
            if(n&1) {
                num_parity++;
            }
            n >>= 1;
        }
        
        
        if(num_parity&1) {
            cout<<"ODD\n";
        } else {
            cout<<"EVEN\n";
        }
    }
}

int main() {
    solve();
    return 0;
}