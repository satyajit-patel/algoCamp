#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>

void solve() {
    int t; cin>>t;
    while(t--) {
        int n,x; cin>>n>>x;
        vi arr(n);
        for(auto& it: arr) {
            cin>>it;
        }
        
        arr.insert(arr.begin(), 0);
        arr.push_back(x);
        // for(auto& it: arr) {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int maxi = INT_MIN;
        for(int i=1; i<arr.size(); i++) {
            int minPetrolNeed = arr[i] - arr[i-1];
            if(i == arr.size()-1) {
                // for going and comming back
                minPetrolNeed *= 2;
            }
            maxi = max(maxi, minPetrolNeed);
        }
        cout<<maxi<<endl;
    }
}


int main() {
	solve();
	return 0;
}