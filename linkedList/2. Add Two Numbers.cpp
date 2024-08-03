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
class Solution {
public:
    void add(int val, ListNode*& head, ListNode*& tail) {
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1 && l2) {
            int sum = l1->val + l2->val + carry;
            int lastDigit = sum % 10;
            carry = sum / 10;

            add(lastDigit, head, tail);
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int sum = l1->val + carry;
            int lastDigit = sum % 10;
            carry = sum / 10;

            add(lastDigit, head, tail);
            l1 = l1->next;
        }
        while(l2) {
            int sum = l2->val + carry;
            int lastDigit = sum % 10;
            carry = sum / 10;

            add(lastDigit, head, tail);
            l2 = l2->next;
        }
        if(carry) {
            add(carry, head, tail);
        }

        return head;
    }
};