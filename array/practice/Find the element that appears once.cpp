int search(int A[], int N){
	    //code
	    if(N == 1) {
	        return A[0];
	    }
	    for(int i=0; i<N; i++) {
	        if(i == 0) {
	            if(A[i+1] != A[i]) {
	                return A[i];
	            }
	        } else if(i == N-1) {
	            if(A[i-1] != A[i]) {
	                return A[i];
	            }
	        } else {
	            if(A[i-1] != A[i] && A[i+1] != A[i]) {
	                return A[i];
	            }
	        }
	    }