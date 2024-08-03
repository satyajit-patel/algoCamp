class Solution {
public:
    /*
        Input: 
            words = ["one.two.three","four.five","six"], 
            separator = "."
        Output: 
            ["one","two","three","four","five","six"]
    */

    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;

        for(auto& it: words) {

            std::stringstream ss(it);
            while(ss.good()) {
                string word;
                std::getline(ss, word, separator);

                if(!word.empty()) {
                    ans.push_back(word);
                }
            }
        }

        return ans;
    }
};