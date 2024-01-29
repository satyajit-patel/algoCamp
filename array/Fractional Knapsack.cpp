/*
struct Item{
    int value;
    int weight;
};
*/
class Solution {
public:
    static bool comp(Item a, Item b) {
        return (a.value*1.0/a.weight) > (b.value*1.0/b.weight);
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr+n, comp);
        double ans = 0;
        for(int i=0; i<n; i++) {
            if(W-arr[i].weight >= 0) {
                ans += arr[i].value;
                W -= arr[i].weight;
            } else {
                ans += (W*(arr[i].value*1.0/arr[i].weight));
                break;
            }
        }
        return ans;
    }
};
