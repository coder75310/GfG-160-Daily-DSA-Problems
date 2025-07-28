/* K-th element of two Arrays :
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array. */


// User function Template for C

int kthElement(int *a, int n, int *b, int m, int k) {
    // Your 
    // code here
    // Ensure a is the smaller array
    if (n > m) return kthElement(b, m, a, n, k);
    
    int low = (0 > k - m) ? 0 : k - m;
    int high = (k < n) ? k : n;
    
    while(low <= high){
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;
        
        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : a[cut1];
        int r2 = (cut2 == m) ? INT_MAX : b[cut2];
        
        if(l1 <= r2 && l2 <= r1) {
            return (l1 > l2) ? l1 : l2;
        } else if (l1 > l2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }
    
    return -1;  // This should never be reached
}
