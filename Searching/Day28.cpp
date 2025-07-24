/* Number of occurrence :
Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[].  */


class Solution {
  public:
  // write your code he
  // Function to find the first occurence of target
  int firstOccurence(vector<int>& arr, int target){
      int low = 0, high = arr.size() -1, result = -1;
      while (low <= high) {
          int mid = low + (high - low) / 2;
          if (arr[mid] == target){
              result = mid;
              high = mid - 1;   // search in left half
          } else if (arr[mid] < target){
              low = mid + 1;
          } else {
              high = mid - 1;
          }
      }
      return result;
  }
  
  // Function to find the last occurence of target
  int lastOccurence(vector<int>& arr, int target){
      int low = 0, high = arr.size() - 1, result = -1;
      while(low <= high) {
          int mid = low + (high - low) / 2;
          if(arr[mid] == target){
              result = mid;
              low = mid + 1;    // search in right half
          } else if (arr[mid] < target) {
              low = mid + 1;
          } else {
              high = mid - 1;
          }
      }
      return result;
  }
  
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first = firstOccurence(arr, target);
        if (first == -1) return 0;   // target not found
        int last = lastOccurence(arr, target);
        return last - first + 1;
    }
};
