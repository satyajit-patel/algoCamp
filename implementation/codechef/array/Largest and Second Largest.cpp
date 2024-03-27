#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(a[i]);
        }
        
        int sum = 0;
        auto it = st.rbegin();
        sum += *it;
        it++;
        sum += *it;
        cout<<sum<<endl;
    }
}
