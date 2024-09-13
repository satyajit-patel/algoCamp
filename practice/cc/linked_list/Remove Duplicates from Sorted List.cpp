/* Linked List Node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

// https://www.codechef.com/practice/course/linked-lists/LINKLISTF/problems/PREP55

class Solution {
  public:
    void add(int data, Node*& head, Node*& tail) {
        if(!head) {
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
            return;
        }
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
  
    Node* removeDuplicates(Node* head) {
        set<int> st;
        while(head) {
            st.insert(head->data);
            head = head->next;
        }
        Node* tail = NULL;
        for(auto& it: st) {
            add(it, head, tail);
        }
        return head;
    }
};