class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string ans = "";
        for(int i=0; i<strs.size(); i++) {
            ans += strs[i];
            if(i != strs.size()-1) {
                ans += "+";
            }
        }
        return ans;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> ans;
        std::stringstream ss(str);
        while(ss.good()) {
            string word;
            std::getline(ss, word, '+');
            ans.push_back(word);
        }
        return ans;
    }
};