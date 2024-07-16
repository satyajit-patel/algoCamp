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
    void dfs(TreeNode* root) {
        // base case
        if(!root) {
            return;
        }

        // pre work
        std::swap(root->left, root->right);
        
        // transition
        dfs(root->left);
        dfs(root->right);
    }

    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push({root});
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                // cout << node->val << " ";

                std::swap(node->left, node->right);
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            // cout << endl;
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root) {
            return NULL;
        }

        // bfs(root);
        dfs(root);

        return root;
    }
};