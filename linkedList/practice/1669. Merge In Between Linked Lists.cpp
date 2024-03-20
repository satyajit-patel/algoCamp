/*
        Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
        Output: [10,1,13,1000000,1000001,1000002,5]
    */

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;

        ListNode* front;
        for(int i=0; i<b; i++) {
            if(i == a-1) {
                front = list1;
            }
            list1 = list1->next;
        }

        // cout<<front->val<<" "<<list1->val;
        ListNode* temp = list2;
        while(list2->next != NULL) {
            list2 = list2->next;
        }

        // cout<<front->val<<" "<<list1->val<<" "<<list2->val;

        list2->next = list1->next;
        front->next = temp;

        return head;
    }