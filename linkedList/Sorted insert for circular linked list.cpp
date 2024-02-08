/*
struct Node {
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
}; */
class Solution {
public:
    Node* newHead;
    Node* newTail;
    
    void add(int x) {
        if(!newHead) {
            Node* newNode = new Node(x);
            newHead = newNode;
            newTail = newNode;
            return;
        }
        Node* newNode = new Node(x);
        newTail->next = newNode;
        newTail = newNode;
    }

    Node *sortedInsert(Node* head, int data) {
        multiset<int> st;
        Node* temp = head;
        int numOfVisit = 0;
        while(temp) {
            if(temp == head) {
                numOfVisit++;
            }
            if(numOfVisit == 2) {
                break;
            }
            st.insert(temp->data);
            temp = temp->next;
        }
        st.insert(data);
       
        newHead = NULL;
        newTail = NULL;
        for(auto& it: st) {
            // cout<<it<<" ";
            add(it);
        }
        // cout<<endl;
        newTail->next = newHead;
        return newHead;
    }
};