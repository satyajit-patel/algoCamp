 /* 
            The structure of Node
            struct Node{
                int data;
                Node *left,*right;
            }; 
            
            
            Example 1:
            Input:
            n = 6
            arr = {67, 34, 82, 12, 45, 78}
            Output:
            135
            Explanation:
            In first test case, the BST for the given input will be-
                            67
                         /     \
                       34       82
                      /   \    /
                     12   45  78
            
            Hence, the required sum= 12 + 45 + 78 = 135
        */

    
        bool isLeaf(Node* root) {
            return !root->left && !root->right;
        }
    
        int state(Node* root) {
            // base case
            if(!root) {
                return 0;
            }
            if(isLeaf(root)) {
                return root->data;
            }
            
            // transition
            int left = state(root->left);
            int right = state(root->right);
            int ans = left + right;
            return ans;
        }
    
        /*You are required to complete below method */
        int sumOfLeafNodes(Node *root ){
             /*Your code here */
             if(isLeaf(root)) {
                 return root->data;
             }
             int ans = state(root);
             return ans;
        }