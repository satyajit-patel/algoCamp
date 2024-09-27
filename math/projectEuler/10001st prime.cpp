#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// https://www.hackerrank.com/contests/projecteuler/challenges/euler007/problem?isFullScreen=true

vector<int> prime;

void sieve() {
    int limit = 1e7+1;
    vector<int> isprime(limit, 1);
    isprime[0] = 0;
    isprime[1] = 0;
    for(int i=2; i*i<=limit; i++) {
        if(isprime[i]) {
            for(int j=i*i; j<limit; j+=i) {
                isprime[j] = 0;
            } 
        }
    }
    for(int i=0; i<limit; i++) {
        if(isprime[i]) {
            prime.push_back(i);
        }
    }
}

void f() {
    sieve();
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        cout << prime[n-1] << endl;
    }
}

signed main() {
    f();
    return 0;    
}