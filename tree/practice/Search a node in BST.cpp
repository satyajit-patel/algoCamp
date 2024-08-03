bool search(Node* root, int x) {
    if(!root) {
        return false;
    }
    if(root->data == x) {
        return true;
    }
    
    bool left = false;
    bool right = false;
    if(x < root->data) {
        left = search(root->left, x);
    } else {
        right = search(root->right, x);
    }
    return left || right;
}
