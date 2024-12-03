#include <iostream>
#include <algorithm>
using namespace std;

// https://codeforces.com/problemset/problem/352/A

int main() {
  int n; cin >> n;
  int nums[n];
  int fiveCount = 0;
  for(int i=0; i<n; i++) {
    cin >> nums[i];
    if(nums[i] == 5) {
      fiveCount++;
    }
  }

  int zeroCount = n - fiveCount;

  // div by 09 => sum of digit have to div by 9
  // div by 10 => 0 have to be at last

  if((zeroCount >= 1) && (fiveCount >= 9)) {
    // but still we have to know can we make fiveCount div of 9
    int temp[n];
    for(int i=0; i<n; i++) {
      temp[i] = 9 * (i+1);
    }
    // 9 18 27 36 45
    int ind = std::upper_bound(temp, temp+n, fiveCount) - temp;
    ind--;
    for(int i=0; i<temp[ind]; i++) {
      cout << 5;
    }
    for(int i=0; i<zeroCount; i++) {
      cout << 0;
    }
  } else if(zeroCount) {
    cout << 0;
  } else {
    cout << -1;
  }

  return 0;
}