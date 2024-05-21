bool evaluateTree(TreeNode* root) {
        // base case
        if(!root->left && !root->right) {
            if(root->val == 1) {
                return true;
            }
            return false;
        }

        // transition
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        if(root->val == 2) {
            return left || right;
        }
        return left && right;
    }