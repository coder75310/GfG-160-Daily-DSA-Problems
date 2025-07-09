// Max Circular Subarray Sum :
// You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. 
// In a circular array, the subarray can start at the end and wrap around to the beginning.
// Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.

  
class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        int totalSum = 0;
        int maxKadane = arr[0], curMax = arr[0];
        int minKadane = arr[0], curMin = arr[0];
        
        for(int i=1; i<arr.size(); ++i){
            curMax = max(arr[i], curMax + arr[i]);
            maxKadane = max(maxKadane, curMax);
            
            curMin = min(arr[i], curMin + arr[i]);
            minKadane = min(minKadane, curMin);
            
            totalSum += arr[i];
        }
        
        totalSum += arr[0]; // include arr[0] which was missed earlier
        
        // If all elements are negative, minKadane == totalSum
        if(totalSum == minKadane)
            return maxKadane;
            
        return max(maxKadane, totalSum - minKadane);
    }
};
