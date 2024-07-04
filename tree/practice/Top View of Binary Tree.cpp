/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
public:
    vector<int> topView(Node *root) {
        map<int, map<int, vector<int>>> mp;
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int xCoOrdinate = it.second.first;
            int level = it.second.second;
            mp[xCoOrdinate][level].push_back(node->data);
            
            if(node->left) {
                q.push({node->left, {xCoOrdinate-1, level+1}});
            }
            if(node->right) {
                q.push({node->right, {xCoOrdinate+1, level+1}});
            }
        }
        vector<vector<int>> vertical;
        for(auto& row: mp) {
            vector<int> temp;
            for(auto& it: row.second) {
                temp.insert(temp.end(), it.second.begin(), it.second.end());
            }
            vertical.push_back(temp);
        }
        
        vector<int> ans;
        for(auto& row: vertical) {
            ans.push_back(row[0]);
        }
        return ans;
    }
};