/* Kadane's Algorithm :
You are given an integer array arr[]. 
You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].

Note : A subarray is a continuous part of an array. */


class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int maxSum = arr[0];        // Start with first element
        int currentSum = arr[0];    // same here 
        
        for(int i=1; i<arr.size(); i++){
            // Either add element or start fresh from current element
            currentSum = max(arr[i], currentSum + arr[i]);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};
