// Smallest Positive Missing :
// You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

// Note: Positive number starts from 1. The array can have negative integers too.


class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        
        // step 1: place element in their correct position
        for(int i=0; i<n; ++i){
            while(arr[i] >= 1 && arr[i] <= n && arr[arr[i] - 1] != arr[i]){
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        // step 2: Find the first place where index doesn't match value
        for(int i=0; i<n; ++i){
            if(arr[i] != i+1){
                return i+1;
            }
        }
        
        // If all values from 1 to n are present
        return n + 1;
    }
};
