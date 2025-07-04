/* Minimize the Heights II :
Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers. */


// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n == 1) return 0;
        
        sort(arr.begin(), arr.end());
        
        int ans = arr[n-1] - arr[0]; // initial max difference
        
        int small = arr[0] + k;
        int big = arr[n-1] - k;
        
        for(int i=0; i<n-1; i++){
            int minHeight = min(small, arr[i+1] - k);
            int maxHeight = max(big, arr[i] + k);
            
            if(minHeight < 0) continue;
            
            ans = min(ans, maxHeight - minHeight);
        }
        
        return ans;
    }
};
