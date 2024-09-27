#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler010/problem?isFullScreen=true

vi prime;

void sieve() {
    int limit = 1000000;
    vi isprime(limit+1, 1);
    isprime[0] = 0;
    isprime[1] = 0;
    for(int i=2; i*i<=limit; i++) {
        if(isprime[i]) {
            for(int j=i*i; j<=limit; j+=i) {
                isprime[j] = 0;
            }
        }
    }
    
    for(int i=0; i<=limit; i++) {
        if(isprime[i]) {
            prime.push_back(i);
        }
    }
}

void solve() {
    int n; cin >> n;
    
    int sum = 0;
    for(auto& it: prime) {
        if(it > n) {
            break;
        }
        sum += it;
    }
    cout << sum << endl;
}

signed main() {
//   solve();
sieve();
int t; cin >> t;
while(t--) {
	solve();
}
  return 0;
}
