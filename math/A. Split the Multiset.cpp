#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;

    /*
      we need "n" ele in ms
      st first we have "1" ele in ms, so we need "n-1" ele more

      1 + (n-1) = n
      but each time we can move atmost "k-1", so we need atleast "#step"
      to reach n

      #step = ceil(n-1 / k-1)

      note:
        floor => A / B
        ceil => (A+B-1) / B;

      dry run:
        6 3

        1---------1--------1--------1--------1---LINK-----1

        so to divide into 3 groups, we need to cut any (k-1) link

        1         1--------1        1--------1---LINK-----1
    */

    int A = n-1;
    int B = k-1;
    cout << (A+B-1) / B << "\n";
  }
  return 0;
}