class Solution {
public:
    bool checkInclusion(string& s1, string& s2) {
        // // TLE
        // if(s1.size() > s2.size()) {
        //     return false;
        // }
        // std::sort(s1.begin(), s1.end());
        // do {
        //     if(s2.find(s1) != -1) {
        //         return true;
        //     }
        // } while(std::next_permutation(s1.begin(), s1.end()));
        // return false;

        std::sort(s1.begin(), s1.end());
        string temp = "";
        for(int i=0; i<s2.size(); i++) {
            temp += s2[i];
            if(temp.size() == s1.size()) {
                string now = temp;
                std::sort(now.begin(), now.end());
                if(s1 == now) {
                    return true;
                }
                temp.erase(temp.begin()+0);
            }
        }
        return false;
    }
};