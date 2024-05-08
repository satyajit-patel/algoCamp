/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

    Input: head = [1,8,9]
    Output: [3,7,8]
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

    vector<int> addLargeNum(vector<int>a, vector<int> b) {
        vector<int> ans;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for(int i=0; i<a.size(); i++) {
            int x = a[i] + b[i] + carry;
            int lastDigit = x % 10;
            carry = x / 10;
            ans.push_back(lastDigit);
        }
        if(carry) {
            int lastDigit = carry % 10;
            carry /= 10;
            ans.push_back(lastDigit);
        }

        // for(auto& it: ans) {
        //     cout<<it<<" ";
        // }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    ListNode* doubleIt(ListNode* head) {
        vector<int> a;
        while(head) {
            a.push_back(head->val);
            head = head->next;
        }
        vector<int> ans = addLargeNum(a, a);
        head = NULL;
        ListNode* tail = NULL;
        for(auto& it: ans) {
            add(it, head, tail);
        }
        return head;
    }
};