#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/sorting/SORTING/problems/CUTOFF

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        // your code goes here
        sort(a, a+n);
        reverse(a, a+n);
        cout<<a[x-1]-1<<endl;
    }

}
