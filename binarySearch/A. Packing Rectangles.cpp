#include <iostream>
using namespace std;
#define int long long

/*
  https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

  input:
    2 3 10
  output:
    9
  
  ex:

    width

    0 1 2 3 4 5 6 7 8
  0   |   |   |   |   
  1   |   |   |   |   
  2----------------
  3   |   |   |   |   
  4   |   |   |   |     Height
  5----------------
  6   |   |   |   |   
  7   |   |   |   |   
  8----------------

  i.e atleast in 9*9 matrix we can easily fit 12 rectangles of size(3*2)
  which is enough to hold 10 rectangle either
*/

bool isGood(int mid, int w, int h, int n) {
  return (mid / w) * (mid / h) >= n;
}

signed main() {
  int w, h, n; cin >> w >> h >> n;

  int i = 1, j = 1, ans = -1;

  while(!isGood(j, w, h, n)) {
    j *= 2;
  }

  while(i <= j) {
    int mid = (i + j) / 2;
    if(isGood(mid, w, h, n)) {
      ans = mid;
      // look for less
      j = mid - 1;
    } else {
      i = mid + 1;
    }
  }

  cout << ans;

  return 0;
}