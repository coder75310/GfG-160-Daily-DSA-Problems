// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int nonZeroIndex = 0;
        
        // First pass: Move all non-zero elements to the beginning
        for(int i=0; i<arr.size(); i++){
            if(arr[i] != 0){
                arr[nonZeroIndex++] = arr[i];
            }
        }
        
        // second pass: Fill the rest with zeros
        while(nonZeroIndex < arr.size()){
            arr[nonZeroIndex++] = 0;
        }
    }
};