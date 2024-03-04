class Solution {
public:
    
    // ["one.two.three","four.five","six"] => ["one","two","three","four","five","six"]
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        // vector<string> ans;
        // for(auto& it:words) {
        //     std::stringstream ss(it);
        //     for(std::string word; std::getline(ss, word, separator);) if(!word.empty()) ans.push_back(word);
        // }
        // return ans;
        
        vector<string> ans;
        for(auto& it:words) {
            std::stringstream ss(it);
            while(ss.good()) {
                std::string word;
                std::getline(ss, word, separator);
                if(!word.empty()) ans.push_back(word);
            }
        }
        return ans;
    }
};