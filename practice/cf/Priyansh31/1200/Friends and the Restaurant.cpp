#include <bits/stdc++.h>
using namespace std;

int f(int n, int* capacity, int* price) {
  int pair = 0;
  multiset<int> pos, neg;
  for(int i=0; i<n; i++) {
    int bill = price[i] - capacity[i];
    if(bill >= 0) {
      pos.insert(bill);
    } else {
      neg.insert(-bill);
    }
  }
  /*
    https://codeforces.com/problemset/problem/1729/D
    6
    2 3 6 9 5 7
    3 2 7 10 6 10
    neg: 1
    pos: 1, 1, 1, 1, 3
    (1, 1), (1, 1,) (1, 3)  
  */
  while(!neg.empty()) {
    auto it = pos.lower_bound(*neg.begin());
    if(it != pos.end()) {
      pos.erase(it);
      neg.erase(neg.begin());
      pair++;
    } else {
      break;
    }
  }
  return pair + (pos.size()/2);
}

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n], b[n];
    for(int i=0; i<n; i++) {
      cin >> a[i];
    }
    for(int i=0; i<n; i++) {
      cin >> b[i];
    }

    cout << f(n, a, b) << endl;
  }
  return 0;
}
