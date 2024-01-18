/*
Structure of the node of the binary tree is as
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
*/

int result;

int dfs(Node* root, int X) {
    // base case
    if(!root) {
        return 0;
    }
    
    // transition
    int head = dfs(root->left, X);
    int tail = dfs(root->right, X);
    int ans = root->data + head + tail;
    if(ans == X) {
        result++;
    }
    return ans;
}

int countSubtreesWithSumX(Node* root, int X) {
    result = 0;
    dfs(root, X);
    return result;
}