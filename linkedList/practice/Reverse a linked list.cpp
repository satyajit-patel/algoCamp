/* Linked List Node structure:
struct Node {
    int data;
    struct Node *next;
}
*/

#include<bits/stdc++.h>
class Solution {
public:
    Node* head;
    Node* tail;
    
    void push_back(int x) {
        if(!head) {
            Node* temp = new Node(x);
            head = temp;
            tail = temp;
            return;
        }
        
        Node* temp = new Node(x);
        tail->next = temp;
        tail = temp;
    }

    struct Node* reverseList(struct Node *_head) {
        Node* temp = _head;
        vector<int> arr;
        while(temp) {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        reverse(arr.begin(), arr.end());
        
        head = NULL;
        tail = NULL;
        for(auto& it: arr) {
            push_back(it);
        }
        return head;
    }
    
};
    