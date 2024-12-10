#include <iostream>
using namespace std;
#define int long long

// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B

signed main() {
  int n, s; cin >> n >> s;
  int a[n];
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  int mini = 1e18;
  int init = 0;
  int sum = 0;

  for(int i=0; i<n; i++) {
    sum += a[i];

    while(sum >= s && init <= i) {
      mini = min(mini, i-init+1);
      sum -= a[init++];
    }
  }

  if(mini == 1e18) {
    cout << -1;
  } else {
    cout << mini;
  }

  return 0;
}