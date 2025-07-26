/* Search in Rotated Sorted Array :
Given a sorted and rotated array arr[] of distinct elements, the task is to find the index of a target key.  
If the key is not present in the array, return -1. */


class Solution {
  public:
  // write yo
    int search(vector<int>& arr, int key) {
        // Code Here
        int low = 0, high = arr.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(arr[mid] == key)
                return mid;
                
                // left half is sorted
                if(arr[low] <= arr[mid]){
                    if(key >= arr[low] && key <= arr[mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                // Right half is sorted
                else {
                    if (key > arr[mid] && key <= arr[high])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
        }
            
        return -1;
        
    }
};
