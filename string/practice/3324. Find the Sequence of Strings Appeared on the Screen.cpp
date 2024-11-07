class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string temp = "";

        for(int i=0; i<target.size(); i++) {
            temp += "a";
            for(char ch='a'; ch<=target[i]; ch++) {
                temp.back() = ch;
                ans.push_back(temp);
            }
        }

        return ans;    
    }
};