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
    /*
        Input: root = [2,2,1,null,1,0,null,0]
        Output: "abc"

        Constraints:
        The number of nodes in the tree is in the range [1, 8500].
        0 <= Node.val <= 25
    */

    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    void state(TreeNode* root, string& minAns, string temp) {
        // base case
        if(!root) {
            return;
        }
        if(isLeaf(root)) {
            char ch = 97 + root->val;
            temp += ch;
            reverse(temp.begin(), temp.end());
            if(temp < minAns) {
                minAns = temp;
            }
            return;
        }

        // transition
        char ch = 97 + root->val;
        state(root->left, minAns, temp + ch);
        state(root->right, minAns, temp + ch);
    }

    string smallestFromLeaf(TreeNode* root) {
        string minAns = "";
        for(int i=0; i<8500+1; i++) {
            minAns += "z";
        }
        state(root, minAns, "");
        return minAns;
    }
};