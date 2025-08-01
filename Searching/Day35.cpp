/* Kth Missing Positive Number in a Sorted Array :
Given a sorted array of distinct positive integers arr[], You need to find the kth positive number that is missing from the arr[]. */


// User function template for C++

class Solution {
  public: 
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        int low=0, high=n-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            int missing = arr[mid] - (mid+1);
            
            if(missing < k){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low + k;
    }
};
