Count Inversions :
Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].


class Solution {
  public:
        // Your co
  long long merge(vector<int>& arr, vector<int>& temp, int left,int mid, int right) {
      int i = left; // left subarray
      int j = mid + 1; // right subarray
      int k = left;     // merged subarray
      long long inv_count = 0;
      
      while(i <= mid && j <= right) {
          if(arr[i] <= arr[j]) {
              temp[k++] = arr[i++];
          } else {
              temp[k++] = arr[j++];
              inv_count += (mid - i + 1);   // count inversions
          }
      }
      
      while( i<= mid) temp[k++] = arr[i++];
      while(j <= right) temp[k++] = arr[j++];
      for(int p = left; p <= right; p++) arr[p] = temp[p];
      
      return inv_count;
  }
  
  // Recursive function to implement merge sort and count inversions
  long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
      long long inv_count = 0;
      if(left < right) {
          int mid = left + (right - left) / 2;
          inv_count += mergeSort(arr, temp, left, mid);
          inv_count += mergeSort(arr, temp, mid + 1, right);
          inv_count += merge(arr, temp, left, mid, right);
      }
      return inv_count;
      
  }
  
  // Main function to be called
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        vector<int> temp(arr.size());
        return mergeSort(arr, temp, 0, arr.size() - 1);
    }
};












