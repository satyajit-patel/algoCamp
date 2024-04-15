/*
        Input: root = [1,2,3]
        Output: 25
        Explanation:
        The root-to-leaf path 1->2 represents the number 12.
        The root-to-leaf path 1->3 represents the number 13.
        Therefore, sum = 12 + 13 = 25.
    */

    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    void state(TreeNode* root, string temp, vector<string>& all) {
        // base case
        if(!root) {
            return;
        }
        if(isLeaf(root)) {
            temp += to_string(root->val);
            all.push_back(temp);
            return;
        }

        // transition
        state(root->left, temp+to_string(root->val), all);
        state(root->right, temp+to_string(root->val), all);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;

        string temp = "";
        vector<string> all;
        state(root, temp, all);

        for(auto& it: all) {
            ans += stoi(it);
        }

        return ans;
    }