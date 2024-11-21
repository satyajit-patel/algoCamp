#include <bits/stdc++.h>
using namespace std;


// https://codeforces.com/contest/2037/problem/C

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    // 2 3 5 7 prime numbers
    // even + even = even (always a composite number)
    // odd + odd = even (always a composite num)
    // 1 3 2 4 or 2 4 1 3 i.e if n <= 4 there is no way
    if(n <= 4) {
      cout << -1 << "\n";
    } else {
      deque<int> dq;
      //                            __________
      //  EVEN EVEN EVEN EVEN EVEN | EVEN ODD | ODD ODD ODD ODD ODD
      //                            ----------
      // just make sure the middle num sum is not prime(composite)
      dq.push_back(4);
      dq.push_back(5);
      for(int i=1; i<=n; i++) {
        if(i == 4 || i == 5) {
          continue;
        }
        if(i & 1) {
          dq.push_back(i);
        } else {
          dq.push_front(i);
        }
      }
      for(auto& it: dq) {
        cout << it << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}