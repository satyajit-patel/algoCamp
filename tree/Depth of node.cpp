class Solution {
public:
    bool is_leaf(Node* root) {
        return root->left == NULL && root->right == NULL;
    }

    int bfs(Node* root) {
        int level = 0;
        int ans = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            level++;
            for(int i = 0; i < n; i++) {
                root = q.front();
                q.pop();
                if(level % 2) {
                    if(is_leaf(root)) {
                        ans = level;
                    }
                }
                
                if(root->left) {
                    q.push(root->left);
                }
                if(root->right) {
                    q.push(root->right);
                }
            }
        }
        return ans;
    }

    int depthOfOddLeaf(Node *root) {
        int ans = bfs(root);
        return ans;
    }
};