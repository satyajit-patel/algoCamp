/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode* root, int target, string& s) {
        // base case
        if(!root) {
            return root;
        }
        if(root->val == target) {
            return true;
        }

        // transition
        s += 'L';
        if(f(root->left, target, s)) {
            return true;
        }
        s.pop_back();

        s.push_back('R');
        if(f(root->right, target, s)) {
            return true;
        }
        s.pop_back();

        return false;
    }

    // bool rightTree(TreeNode* root, int x, string& s) {
    //     // base case
    //     if(!root) {
    //         return root;
    //     }
    //     if(root->val == x) {
    //         return true;
    //     }

    //     // transition
    //     bool left = rightTree(root->left, x, s);
    //     bool right = rightTree(root->right, x, s);

    //     if(left && !right) {
    //         s += 'L';
    //     } else if(!left && right) {
    //         s += 'R';
    //     }
    //     bool ans = left || right;
    //     return ans;
    // }

    // bool leftTree(TreeNode* root, int x, string& s) {
    //     // base case
    //     if(!root) {
    //         return root;
    //     }
    //     if(root->val == x) {
    //         return true;
    //     }

    //     // transition
    //     bool left = leftTree(root->left, x, s);
    //     bool right = leftTree(root->right, x, s);

    //     if(left || right) {
    //         s += 'U';
    //     }
    //     bool ans = left || right;
    //     return ans;
    // }

    TreeNode* getLca(TreeNode* root, int x, int y) {
        // base case
        if(!root || (root->val == x) || (root->val == y)) {
            return root;
        }

        // transition
        auto left = getLca(root->left, x, y);
        auto right = getLca(root->right, x, y);

        if(left && !right) {
            return left;
        } else if(left && right) {
            return root;
        }
        return right;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = getLca(root, startValue, destValue);

        // string left = "";
        // leftTree(lca, startValue, left);
        // string right = "";
        // rightTree(lca, destValue, right);
        // std::reverse(right.begin(), right.end());

        string temp_left = "";
        f(lca, startValue, temp_left);
        string right = "";
        f(lca, destValue, right);
        string left(temp_left.size(), 'U');

        return left + right;
    }
};