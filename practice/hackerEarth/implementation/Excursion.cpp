#include <bits/stdc++.h>
using namespace std;

// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/excursion-2d080f3a/

int main() {
	int t; cin>>t;
	while(t--) {
		int n,m,k; cin>>n>>m>>k;

		int room = 0;
		room += ceil((double)n/k);
		room += ceil((double)m/k);
		cout<<room<<endl;
	}
	return 0;
}