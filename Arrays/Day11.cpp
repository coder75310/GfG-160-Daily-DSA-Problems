/* Maximum Product Subarray :
Given an array arr[] that contains positive and negative integers (may contain 0 as well). 
Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the answer fits in a 32-bit integer. */


class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        int max_so_far = arr[0];
        int max_ending_here = arr[0];
        int min_ending_here = arr[0];
        
        for(int i=1;i<n; ++i){
            if(arr[i]<0)
                swap(max_ending_here, min_ending_here);
                
            max_ending_here = max(arr[i], arr[i] * max_ending_here);
            min_ending_here = min(arr[i], arr[i] * min_ending_here);
                
            max_so_far = max(max_so_far, max_ending_here);
        }
        
        return max_so_far;
    }
};
