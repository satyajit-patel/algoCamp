/* The structure of the binary tree is as follows
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
public:
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }

    bool bfs(Node* root, int maxHeight) {
        queue<pair<Node*, int>> q;
        q.push({root, 1});
        while(!q.empty()) {
            root = q.front().first;
            int curHeight = q.front().second;
            q.pop();
            
            if(isLeaf(root) && curHeight != maxHeight) {
                return false;
            }
            if(root->left) {
                q.push({root->left, curHeight+1});
            }
            if(root->right) {
                q.push({root->right, curHeight+1});
            }
        }
        return true;
    }

    int getMaxHeight(Node* root) {
        // base case
        if(!root) {
            return 0;
        }
        
        // transition
        int left = getMaxHeight(root->left);
        int right = getMaxHeight(root->right);
        int ans = max(left, right) + 1;
    }
    
    bool check(Node *root) {
        int maxHeight = getMaxHeight(root);
        bool ans = bfs(root, maxHeight);
        return ans;
    }
};
