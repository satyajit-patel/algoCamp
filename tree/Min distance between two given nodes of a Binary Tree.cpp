/*
struct Node {
    int data;
    Node* left, * right;
}; */

class Solution{
public:
    int bfs(Node* node, int target) {
        queue<pair<Node*, int>> q;
        q.push({node, 0});
        while(!q.empty()) {
            node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if(node->data == target) {
                return dist;
            }
            if(node->left) {
                q.push({node->left, dist+1});
            }
            if(node->right) {
                q.push({node->right, dist+1});
            }
        }
    }

    Node* getLca(Node* root, int a, int b) {
        // base case
        if(!root || root->data==a || root->data==b) {
            return root;
        }
        
        // transition
        Node* left = getLca(root->left, a, b);
        Node* right = getLca(root->right, a, b);
        if(left && right) {
            return root;
        } else if(left && !right) {
            return left;
        } else {
            return right;
        }
    }
    
    int findDist(Node* root, int a, int b) {
        Node* lca = getLca(root, a, b);
        int x = bfs(lca, a);
        int y = bfs(lca, b);
        return x + y;
    }
};