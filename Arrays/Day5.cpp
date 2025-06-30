class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = n-2;
        
        // step 1: Find first decreasing element from right
        while(i>=0 && arr[i] >= arr[i+1]){
            i--;
        }
        
        if(i>=0){
        // step 2: Find the element just greater than arr[i]
            int j = n-1;
            while(arr[j] <= arr[i]){
                j--;
            }
            
        // step 3: Swap arr[i] and arr[j]
            swap(arr[i], arr[j]);
        }
        
        // step 4: Reverse the suffix starting at i+1
        reverse(arr.begin() + i+1, arr.end());
    }
};