class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        std::sort(target.begin(), target.end());

        return arr == target;
    }
};