/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Linked List Node structure:
struct Node {
    int data;
    struct Node *next;
}
*/

#include<bits/stdc++.h>
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

Node* sortedMerge(Node* head1, Node* head2)  {  
    Node* temp;
    
    temp = head1;
    vector<int> A;
    while(temp) {
        A.push_back(temp->data);
        temp = temp->next;
    }
    temp = head2;
    vector<int> B;
    while(temp) {
        B.push_back(temp->data);
        temp = temp->next;
    }
    
    int i = 0, j = 0;
    vector<int> C;
    while(i < A.size() && j < B.size()) {
        if(A[i] <= B[j]) {
            C.push_back(A[i]);
            i++;
        } else {
            C.push_back(B[j]);
            j++;
        }
    }
    while(i < A.size()) {
        C.push_back(A[i]);
        i++;
    }
    while(j < B.size()) {
        C.push_back(B[j]);
        j++;
    }
    
    head = NULL;
    tail = NULL;
    for(auto& it: C) {
        push_back(it);
    }
    return head;
}  
