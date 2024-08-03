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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        // corner case
        if(depth == 1) {
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            // temp->right = NULL;
            root = temp;
        }

        while(!q.empty()) {
            int n = q.size();
            level++;

            for(int i=0; i<n; i++) {
                TreeNode* P = q.front();
                q.pop();

                if(level == depth-1) {
                    // cout<<"OK\n";
                    TreeNode* temp1 = new TreeNode(val);
                    temp1->left = P->left;
                    P->left = temp1;
                    q.push(temp1);
                    
                    TreeNode* temp2 = new TreeNode(val);
                    temp2->right = P->right;
                    P->right = temp2;
                    q.push(temp2);
                } else {
                    if(P->left) {
                        q.push(P->left);
                    }
                    if(P->right) {
                        q.push(P->right);
                    }
                }
            }
        }
        return root;
    }
};