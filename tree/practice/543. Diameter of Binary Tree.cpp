int maxi;
    int f(TreeNode* root) {
        // base case
        if(!root) {
            return 0;
        }

        // transition
        int left = f(root->left);
        int right = f(root->right);
        int ans = std::max(left, right) + 1;
        maxi = std::max(maxi, (left + right));
        // cout<<ans<<" ";
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxi = 0;
        int ans = f(root);
        return maxi;
        return ans;
    }