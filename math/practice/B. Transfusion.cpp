#include <iostream>
using namespace std;
#define int long long

signed main() {

  // https://codeforces.com/contest/2050/problem/B
  // should be of same parity
  // avg should be same since begining (as add sub not gonna change anything)
  // and avg must be an integer

  int t; cin >> t;
  while(t--) {
    int oddPosSum = 0;
    int evenPosSum = 0;
    int oddCount = 0;
    int evenCount = 0;
    int n; cin >> n;
    for(int i=0; i<n; i++) {
      int x; cin >> x;
      if(i & 1) {
        oddCount++;
        oddPosSum += x;
      } else {
        evenCount++;
        evenPosSum += x;
      }
    }


    bool isInt = true;
    int oddAvg = oddPosSum / oddCount;
    int rem = oddPosSum % oddCount;
    if(rem != 0) {
      isInt = false;
    }
    int evenAvg = evenPosSum / evenCount;
    rem = evenPosSum % evenCount;
    if(rem != 0) {
      isInt = false;
    }

    if(isInt && (oddAvg == evenAvg)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}