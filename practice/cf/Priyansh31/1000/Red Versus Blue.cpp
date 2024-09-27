#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1659/A

void solve() {
  int t; cin >> t;
  while(t--) {
    int n, r, b; cin >> n >> r >> b;
    /*
      7 4 3
      step 0
      _______B_______B_______B______

      step 1
      ___R____B___R____B___R____B___R___

      6 5 1
      step 0
      _______B_______

      step 1
      ___RRR____B___RR____
    */

    int regionCount = b + 1;
    int group = r / regionCount;
    int left = r % regionCount;

    string ans = "";
    bool first = true;
    for(int i=0; i<regionCount; i++) {
      ans += string(group, 'R');
      if(first || (i != regionCount-1)) {
        ans += 'B';
        first = false;
      }
    }
    // cout << ans << endl;
    bool flag = true;
    for(int i=0; i<ans.size() && left; i++) {
      if(flag) {
        // cout << "Bruce was Here \n";
        ans.insert(ans.begin()+i, 'R');
        flag = false;
        left--;
      }
      if(ans[i] == 'B') {
        flag = true;
      }
    }
    cout << ans << endl;
  }
}

int main() {
  solve();
//   vector<int> nums = {10, 20, 30, 40, 50};
//   nums.insert(nums.begin()+3, 300);
//   for(auto& it: nums) {
//     cout << it << " ";
//   }
//   cout << endl;

  return 0;
}