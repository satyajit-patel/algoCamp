/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 /*
    Input: head = [5,2,13,3,8]
    Output: [13,8]
 */
class Solution {
public:
    void add(int val, ListNode* &head, ListNode* &tail) {
        if(!head) {
            ListNode* newNode = new ListNode(val);
            head = newNode;
            tail = newNode;
            return;
        }

        ListNode* newNode = new ListNode(val);
        tail->next = newNode;
        tail = newNode;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* P = head;
        vector<int> a;
        while(P) {
            a.push_back(P->val);
            P = P->next;
        }

        // monotonic stack
        stack<int> st;
        for(int i=0; i<a.size(); i++) {
            while(!st.empty() && a[i] > st.top()) {
                st.pop();
            }

            st.push(a[i]);
        }

        a.clear();
        while(!st.empty()) {
            a.push_back(st.top());
            st.pop();
        }
        reverse(a.begin(), a.end());

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        for(auto& it: a) {a.clear();
            add(it, newHead, newTail);
        }
        return newHead;
    }
};