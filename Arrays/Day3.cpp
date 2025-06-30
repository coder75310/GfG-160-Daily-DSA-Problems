/* Reverse an Array :
You are given an array of integers arr[]. Your task is to reverse the given array.

Note: Modify the array in place. */

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int left = 0, right = arr.size() - 1;
        while(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};
