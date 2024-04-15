#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>

/*

*/

void solve() {
	int t; cin>>t;
	while(t--) {
		vvi mat(10, vi(10));

		int value = 1;
		int totEle = 10 * 10;
		int curEle = 0;

		int top = 0;
		int bottom = mat.size()-1;
		int left = 0;
		int right = mat[0].size()-1;

		while(curEle < totEle) {
			// top
			for(int i=left; i<=right && curEle<totEle; i++) {
				curEle++;
				mat[top][i] = value;
			}
			top++;

			// right
			for(int i=top; i<=bottom && curEle<totEle; i++) {
				curEle++;
				mat[i][right] = value;
			}
			right--;

			// bottom
			for(int i=right; i>=left && curEle<totEle; i--) {
				curEle++;
				mat[bottom][i] = value;
			}
			bottom--;

			// left
			for(int i=bottom; i>=top && curEle<totEle; i--) {
				curEle++;
				mat[i][left] = value;
			}
			left++;

			// increase the value
			value++;
		}

		// for(auto& row: mat) {
		// 	for(auto& it: row) {
		// 		cout<<it<<" ";
		// 	}
		// 	cout<<endl;
		// }

		char grid[10][10];
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				cin>>grid[i][j];
			}
		}

		int ans = 0;
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				if(grid[i][j] == 'X') {
					ans += mat[i][j];
				}
			}
		}

		cout<<ans<<endl;
	}
}

int main() {
	solve();
	return 0;
}
