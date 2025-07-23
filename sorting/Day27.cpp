/* Merge Without Extra Space :
Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. 
Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements. */


class Solution {
  public:
  // Write your 
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size();
        int gap = (n + m + 1) / 2; // initial gap
        
        while(gap > 0) {
            int i = 0, j = gap;
            
            while(j < n + m){
                int val1, val2;
                
                // determine values from combined virtual array
                if(i < n) val1 = a[i];
                else val1 = b[i - n];
                
                if(j < n) val2 = a[j];
                else val2 = b[j - n];
                
                if(val1 > val2){
                    // swap if out of order
                    if(i < n && j < n)
                        swap(a[i], a[j]);
                    else if(i < n && j >= n)
                        swap(a[i], b[j - n]);
                    else
                        swap(b[i - n], b[j - n]);
                }
                
                i++, j++;
            }
            
            if(gap == 1) break;
            gap = (gap + 1) / 2;
        }
    }
};
