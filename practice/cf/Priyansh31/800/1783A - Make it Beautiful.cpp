#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
// #define int long long

void solve() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vi a(n);
		for(auto& it: a) {
			cin>>it;
		}

		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		if(a[0] == a[n-1]) {
			cout<<"NO\n";
		} else {
			if(a[0] != a[1]) {
				cout<<"YES\n";
				for(auto& it: a) {
					cout<<it<<" ";
				}
				cout<<endl;
			} else {
				int index = 2;
				while(a[index] == a[1]) {
					index++;
				}
				swap(a[index], a[1]);

				cout<<"YES\n";
				for(auto& it: a) {
					cout<<it<<" ";
				}
				cout<<endl;
			}
		}
	}
}

signed main() {
	solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
// #define int long long

void solve() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vi a(n);
		for(auto& it: a) {
			cin>>it;
		}

		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		if(a[0] == a[n-1]) {
			cout<<"NO\n";
		} else {
			if(a[0] != a[1]) {
				cout<<"YES\n";
				for(auto& it: a) {
					cout<<it<<" ";
				}
				cout<<endl;
			} else {
				int index = 2;
				while(a[index] == a[1]) {
					index++;
				}
				swap(a[index], a[1]);

				cout<<"YES\n";
				for(auto& it: a) {
					cout<<it<<" ";
				}
				cout<<endl;
			}
		}
	}
}

signed main() {
	solve();
	return 0;
}
