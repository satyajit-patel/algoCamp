#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(2) => iterator at index 2
// order_of_key(2) => index of first occurance of element 2

#define endl "\n"
#define vi vector<int>
#define vc vector<char>

// https://cses.fi/problemset/task/1667

int main() {
  // fast IO
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // ----------------------------------------------------------------------------
  int n, m; cin >> n >> m;
  vi adj[n+1];
  for(int i=0; i<m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

//   // bfs TLE
//   int src = 1;
//   int dest = n;
//   vi vis(dest+1, 0);
//   vis[src] = 1;
//   bool flag = false;
//   vi path;
//   path.push_back(src);
//   queue<pair<int, vi>> q;
//   q.push({src, path});

//   while(!q.empty()) {
//     auto it = q.front();
//     q.pop();
//     src = it.first;
//     path = it.second;

//     if(src == dest) {
//       flag = true;
//       break;
//     }

//     for(auto& child: adj[src]) {
//       if(!vis[child]) {
//         vis[child] = 1;
//         path.push_back(child);
//         q.push({child, path});
//         path.pop_back();
//       }
//     }
//   }

//   if(!flag) {
//     cout << "IMPOSSIBLE";
//     return 0;
//   }
//   cout << path.size() << endl;
//   for(auto& it: path) {
//     cout << it << " ";
//   }

  // bfs 
  int src = 1;
  int dest = n;

  vi parent(n+1, 0);
  parent[src] = -1;

  queue<int> q;
  q.push(src);

  while(!q.empty()) {
    int node = q.front();
    q.pop();

    for(auto& child: adj[node]) {
      if(!parent[child]) {
        parent[child] = node;
        q.push(child);
      }
    }
  }

  int node = dest;
  if(!parent[node]) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  vi path;
  while(node != -1) {
    path.push_back(node);
    node = parent[node]; // update where it came from
  }
  reverse(path.begin(), path.end());

  cout << path.size() << endl;
  for(auto& it: path) {
    cout << it << " ";
  }
 // ----------------------------------------------------------------------------
 return 0;
}
