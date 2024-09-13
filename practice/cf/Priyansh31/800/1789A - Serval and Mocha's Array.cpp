#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long

int my_gcd(int a, int b) {
	if(!b) {
		return a;
	}
	return my_gcd(b, a%b);
}

void solve() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vi a(n);
		for(auto& it: a) {
			cin>>it;
		}

		bool ok = false;
		/*
			gcd(a, b) = min(a, b)
			so adding an ele to it will never increase the gcd 
			but it can it can decrease it

			lets gcd(10, 20) = 10
			so 10 is > 2 which is not good
			so to make it good me must find gcd as 1 or 2
			otherwise the cases will be impossible
		*/
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(my_gcd(a[i], a[j]) <= 2) {
					ok = true;
					break;
				}
			}
			if(ok) {
				break;
			}
		}
		
		if(ok) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
}

int main() {
	solve();
	return 0;
}
