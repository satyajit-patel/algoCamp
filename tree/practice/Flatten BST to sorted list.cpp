/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    Node* newRoot;
    Node* tail;
    void add(int data) {
        if(!newRoot) {
            Node* newNode = new Node(data);
            newRoot = newNode;
            tail = newNode;
            return;
        }
        Node* newNode = new Node(data);
        tail->right = newNode;
        tail = newNode;
    }

    void inorder(Node* node, vector<int>& A) {
        // base case
        if(!node) {
            return;
        }
        
        // transition
        inorder(node->left, A);
        A.push_back(node->data);
        inorder(node->right, A);
    }

    Node *flattenBST(Node *root) {
        vector<int> A;
        inorder(root, A);
        newRoot = NULL;
        tail = NULL;
        for(auto& it: A) {
            add(it);
        }
        return newRoot;
    }
};
