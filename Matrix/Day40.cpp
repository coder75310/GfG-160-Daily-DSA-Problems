/* Search in a sorted Matrix :
Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.
Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is 
greater than the last element of the (i-1)th row. */


class Solution {
  public:
  // Your code is 
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int r=0, c=mat[0].size()-1, n=mat.size();
        while(r<n && c>=0){        

            if(mat[r][c] == x) return true;
            else if(mat[r][c] < x) r++;
            else c--;
        }
        
        return false;
    }
};
