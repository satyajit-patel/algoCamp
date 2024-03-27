#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/arrays/ARRAYS/problems/DISCOUNTT

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        // your code goes here
        
        int cost_without_coupon = 0;
        for(int i=0; i<n; i++) {
            cost_without_coupon += a[i];
        }
        int cost_with_coupon = x;
        for(int i=0; i<n; i++) {
            if(a[i] > y) {
                int discount_cost = a[i] - y;
                cost_with_coupon += discount_cost;
            }
        }
        if(cost_with_coupon < cost_without_coupon) {
            cout<<"COUPON\n";
        } else {
            cout<<"NO COUPON\n";
        }
    }

}
