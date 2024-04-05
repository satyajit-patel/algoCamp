#include<bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

// int main() {
// 	int t;
// 	cin >> t;
// 	while(t--)
// 	{
// 	    string s;
// 	    cin >> s;
// 	    int count=0;
// 	    for(int i=0;i<s.size();i++)
// 	    {
// 	        if(s[i]=='x' && s[i+1]=='y' || s[i]=='y' && s[i+1]=='x')
//             {
//                 count++;
//                 i++;
//             }
// 	    }
	    
// 	    cout << count << endl;
// 	}
// 	return 0;
// }

// https://www.codechef.com/practice/course/greedy-algorithms/INTGRA01/problems/XYSTR

void solve() {
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        
        int n = s.size();
        int ans = 0;
        for(int i=1; i<n; i++) {
            if(s[i] == 'x' && s[i-1] == 'y') {
                ans++;
                i++;
            } else if(s[i] == 'y' && s[i-1] == 'x') {
                ans++;
                i++;
            }
        }
        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}