// Node is defined as:
// struct Node{
//   int data;
//   Node* next;
//   Node(int data){
//       this->data = data;
//       this->next = nullptr;
//   }
// }

// https://www.codechef.com/practice/course/linked-lists/LINKLISTF/problems/CRITLIST

int solve(Node* head){
    int ans = 0;
    
    vector<int> arr;
    while(head) {
        arr.push_back(head->data);
        head = head->next;
    }
    for(int i=1; i<arr.size()-1; i++) {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            // local maxima
            ans++;
        } else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
            // local minima
            ans++;
        }
    }
    
    return ans;
}