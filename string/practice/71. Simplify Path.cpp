class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ds; // data structure
        std::stringstream ss(path);
        while(ss.good()) {
            string word;
            std::getline(ss, word, '/');
            if(!word.empty()) {
                // cout<<word<<endl;
                if(word == ".") {
                    continue;
                } else if(word == "..") {
                    if(!ds.empty()) {
                        ds.pop_back();
                    }
                } else {
                    ds.push_back('/' + word);
                }
            }
        }

        string ans = "";
        for(auto& it: ds) {
            ans += it;
        }
        if(ans.empty()) {
            return "/";
        }
        return ans;
    }
};