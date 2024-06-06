class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n%groupSize) {
            return false;
        }

        map<int, int> map;
        for(auto& it: hand) {
            map[it]++;
        }

        while(!map.empty()) {
            int currNum = map.begin()->first;
            for(int i=0; i<groupSize; i++) {
                if(map[currNum+i] == 0) {
                    return false;
                }
                map[currNum+i]--;
                if(map[currNum+i] == 0) {
                    map.erase(currNum+i);
                }
            }
        }

        return true;
    }
};