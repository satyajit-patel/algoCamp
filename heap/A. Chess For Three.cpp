#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int p1, p2, p3; cin >> p1 >> p2 >> p3;

    priority_queue<int> pq;
    if(p1) {
      pq.push(p1);
    }
    if(p2) {
      pq.push(p2);
    }
    if(p3) {
      pq.push(p3);
    }

    int draw = 0;
    while(pq.size() >= 2) {
      int x = pq.top();
      pq.pop();
      int y = pq.top();
      pq.pop();

      draw++;
      x--;
      y--;
      if(x) {
        pq.push(x);
      }
      if(y) {
        pq.push(y);
      }
    }
    if(!pq.empty()) {
      if(pq.top() & 1) {
        cout << -1;
      } else {
        cout << draw;
      }
    } else {
      cout << draw;
    }
    cout << "\n";
  }
  return 0;
}