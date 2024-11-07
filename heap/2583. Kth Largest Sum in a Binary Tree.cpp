/**
 * Definition for a binary tree root.
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
    /*
        [5,8,9,2,1,3,7], k = 4

                        5
                8               9
            2       1       3      7
    */

    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            long long sum = 0;
            for(int i=0; i<n; i++) {
                root = q.front();
                q.pop();
                sum += root->val * 1LL;
                if(root->left) {
                    q.push({root->left});
                }
                if(root->right) {
                    q.push({root->right});
                }
            }
            pq.push(sum * -1);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        if(pq.size() != k) {
            return -1;
        }
        return pq.top() * -1;
    }
};