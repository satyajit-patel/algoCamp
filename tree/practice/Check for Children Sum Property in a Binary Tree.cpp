/*
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution{
public:
    int dfs(Node* root, bool& ans) {
        // base case
        if(!root) {
            return 0;
        }
        if(!root->left && !root->right) {
            return root->data;
        }
        
        // transition
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        if(left+right != root->data) {
            ans = false;
        }
        return root->data;
    }

    int isSumProperty(Node *root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }
};
