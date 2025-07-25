/* Sorted and Rotated Minimum :
A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it.  */


  class Solution {
  public:
  // Your co
    int findMin(vector<int>& arr) {
        // complete the function here
        int low = 0, high = arr.size() - 1;
        
        while(low < high){
            int mid = low + (high - low) / 2;
            
            if(arr[mid] > arr[high]){
                // Minimum must be in the right part
                low = mid + 1;
            } else {
                 // Minimum is at mid or to the left
                 high = mid;
            }
        }
        
        return arr[low];    // or arr[high], both are equal here
    }
};
