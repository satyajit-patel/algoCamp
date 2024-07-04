/* A binary tree node

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> horizontal;
    if(!root) {
        return horizontal;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        vector<int> temp;
        for(int i=0; i<n; i++) {
            Node* node = q.front();
            q.pop();

            temp.push_back(node->data);

            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push({node->right});
            }
        }
        horizontal.push_back(temp);
    }
    return horizontal;
}

vector<int> leftView(Node* root) {
    vector<vector<int>> horizontal = levelOrder(root);

    vector<int> ans;
    for(auto& row: horizontal) {
        ans.push_back(row[0]);
    }
    return ans;
}
