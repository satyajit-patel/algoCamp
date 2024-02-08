// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-137/problems
class Solution {
  public:
    int candyShop(int n, vector<int> &candies) {
        int minSum = INT_MAX;
        map<int, int> map;
        for(int i=0; i<n; i++) {
            map[candies[i]]++;
        }
        int uniqueSize = map.size();
        
        map.clear();
        int curSum = 0, init = 0;
        for(int i=0; i<n; i++) {
            curSum += candies[i];
            map[candies[i]]++;
            
            while(map.size() == uniqueSize) {
                minSum = min(minSum, curSum);
                curSum -= candies[init];
                map[candies[init]]--;
                if(map[candies[init]] == 0) {
                    map.erase(candies[init]);
                }
                init++;
            }
        }
        return minSum;
    }
};
