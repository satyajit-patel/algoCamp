class Solution {
public:
    int search(int A[], int l, int h, int key) {
        /*
                /
               /
              /
             /
            /
            .................
                            /
                           /
                          /
                         /
        */
        
        while(l <= h) {
            int mid = (l + h) / 2;
            if(A[mid] == key) {
                return mid;
            }
            if(A[mid] >= A[l]) {
                // upper part
                if(key >= A[l] && key < A[mid]) {
                    // target is in left
                    h = mid - 1; // discard right
                } else {
                    l = mid + 1;
                }
            } else {
                // lower curve
                if(key > A[mid] && key <= A[h]) {
                    // target is in right
                    l = mid + 1; // discard left
                } else {
                    h = mid - 1;
                }
            }
            
        }
        return -1;
    }
};
