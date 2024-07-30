class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        for(int bit=0; bit<32; bit++) {
            if(n & (1 << bit)) {
                count++;
            }
        }

        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans;

        for(int ele=0; ele<=n; ele++) {
            ans.push_back(hammingWeight(ele));
        }

        return ans;
    }
};