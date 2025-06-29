class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
            d = d % n;
            
        // step 1: Reverse first d elements
        reverse(arr.begin(), arr.begin() + d);
        
        // step 2: Reverse the remmaining elements
        reverse(arr.begin()+d, arr.end());
        
        // step 3: Reverse the whole array
        reverse(arr.begin(), arr.end());
    }
};