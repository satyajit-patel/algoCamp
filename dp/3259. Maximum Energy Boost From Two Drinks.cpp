class Solution {
public:
    /*
        Input: energyDrinkA = [4,1,1], energyDrinkB = [1,1,3]
        Output: 7
        Explanation:
        To gain an energy boost of 7:
        
        Drink the energy drink A for the first hour.
        Switch to the energy drink B and we lose the energy boost of the second hour.
        Gain the energy boost of the drink B in the third hour.
    */

    vector<int> A, B;
    vector<vector<long long>> dp;

    long long state(int i, int flag) {
        // base case
        if(i >= A.size()) {
            return 0;
        }
        if(dp[i][flag] != -1) {
            return dp[i][flag];
        }

        // transition
        long long energy = 0;
        if(flag) {
            energy = A[i];
        } else {
            energy = B[i];
        }
        long long notSkip = state(i+1, flag);
        // if we swith to another drink then
        // we will not get the energy of next hour
        long long skipAnsSwitch = state(i+2, !flag);
        return dp[i][flag] = energy + std::max(notSkip, skipAnsSwitch);
    }

    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        A = energyDrinkA;
        B = energyDrinkB;
        dp.resize(A.size()+1, vector<long long>(2+1, -1));
        long long ans = std::max(state(0, 0), state(0, 1));
        return ans;
    }
};