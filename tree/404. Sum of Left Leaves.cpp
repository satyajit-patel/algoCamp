/*
        Input: root = [3,9,20,null,null,15,7]
        Output: 24
        Explanation: 
        There are two left leaves in the binary tree, with values 9 and 15 respectively.
    */

    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    int state(TreeNode* root, bool isLeft = false) {
        // base case
        if(!root) {
            return 0;
        }
        if(isLeaf(root) && isLeft) {
            return root->val;
        }

        // transition
        int left = state(root->left, true);
        int right = state(root->right, false);
        int ans = left + right;
        return ans;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = state(root);
        return ans;
    }