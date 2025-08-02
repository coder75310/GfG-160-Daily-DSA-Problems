/* Second Largest:
Given an array of positive integers arr[], return the second largest element from the array.
If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element. */


int getSecondLargest(int *arr, int n) { 
    ///////////////////
    // code here
    if(n<2)
        return -1;
    
    int first = -1,second = -1;    
        
    for(int i=0; i<n; i++){
        if(arr[i] > first){
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] < first){
            second = arr[i];
        }
            
    }    
    
    return second;
}






