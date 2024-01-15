/* node for linked list:
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
    
class Solution {
public:
    Node* head;
    Node* tail;
    
    void push_back(int x) {
        if(!head) {
            Node* P = new Node(x);
            head = P;
            tail = P;
            return;
        }
        Node* P = new Node(x);
        tail->next = P;
        tail = P;
    }

    vector<int> f(vector<int>& x, vector<int>& y) {
        vector<int> ans;
        std::reverse(x.begin(), x.end());
        std::reverse(y.begin(), y.end());
        int size = std::min(x.size(), y.size());
        int carry = 0;
        for(int i=0; i<size; i++) {
            int value = x[i] + y[i] + carry;
            int digit = value % 10;
            carry = value / 10;
            ans.push_back(digit);
        }
        if(x.size() > size) {
            for(int i=size; i<x.size(); i++) {
                int value = x[i] + carry;
                int digit = value % 10;
                carry = value / 10;
                ans.push_back(digit);
            }
        }
        if(y.size() > size) {
            for(int i=size; i<y.size(); i++) {
                int value = y[i] + carry;
                int digit = value % 10;
                carry = value / 10;
                ans.push_back(digit);
            }
        }
        while(carry) {
            int digit = carry % 10;
            carry /= 10;
            ans.push_back(digit);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }

    struct Node* addTwoLists(struct Node* first, struct Node* second) {
        vector<int> x, y;
        Node* P = first;
        while(P) {
            x.push_back(P->data);
            P = P->next;
        }
        P = second;
        while(P) {
            y.push_back(P->data);
            P = P->next;
        }
        head = NULL;
        tail = NULL;
        vector<int> ans = f(x, y);
        for(auto& it: ans) {
            push_back(it);
        }
        return head;
    }
};
