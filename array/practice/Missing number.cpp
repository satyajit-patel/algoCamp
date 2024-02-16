int missingNumber(int A[], int N) {
    // 1 num is missing so sizw = size - 1
    sort(A, A+(N-1));
    for(int i=0; i<N-1; i++) {
        if(A[i] != i+1) {
            return i+1;
        }
    }
    return N;
}