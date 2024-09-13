#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/arrays/ARRAYS/problems/KITCHENCOST

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int j=0;j<n;j++){
            cin>>b[j];
        }
        // your code goes here
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(a[i] >= x) {
                sum += b[i];
            }
        }
        cout<<sum<<endl;
    }

}
