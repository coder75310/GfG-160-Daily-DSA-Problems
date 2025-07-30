/* Aggressive Cows :
You are given an array with unique elements of stalls[], which denote the positions of stalls. 
You are also given an integer k which denotes the number of aggressive cows. 
The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible. */


// User function Template for C

// Comparision function for qsort
int compare(const void *a, const void *b){
    // y
    return (*(int*)a - *(int*)b);
}

// bool isPossible(int stalls[], int n, int k, int mid) {
int isPossible(int stalls[], int n, int k, int mid) {
    int count = 1;
    int last_pos = stalls[0];
    
    for(int i = 1; i < n; i++){
        if(stalls[i] - last_pos >= mid) {
            count++;
            last_pos = stalls[i];
        }
    }
    
    return count >= k;
}

int aggressiveCows(int *stalls, int n, int k) {
    // code here
    qsort(stalls, n, sizeof(int), compare);
    
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if (isPossible(stalls, n, k, mid)) {
            ans = mid;      // valid, try for more
            low = mid  + 1;
        } else {
            high = mid - 1;     // Not possible, reduce distance
        }
    }
    
    return ans;
}
