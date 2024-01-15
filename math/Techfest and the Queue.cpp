class Solution {
public:
    int f(int x) {
        int count = 0;
        for(int i=2; i*i<=x; i++) {
            while(x%i == 0) {
                count++;
                x /= i;
            }
        }
        if(x != 1) {
            count++;
        }
        return count;
    }

	int sumOfPowers(int a, int b){
	    int ans = 0;
	    for(int i=a; i<=b; i++) {
	        ans += f(i);
	    }
	    return ans;
	}
};