/* Search in a row-wise sorted matrix :
Given a row-wise sorted 2D matrix mat[][] of size n x m and an integer x, find whether element x is present in the matrix.
Note: In a row-wise sorted matrix, each row is sorted in itself, i.e. for any i, j within bounds, mat[i][j] <= mat[i][j+1]. */




class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size(), c=mat[0].size()-1;
        for(int i=0; i<n; i++){
            if(mat[i][0] <= x && mat[i][c] >= x){
                int l=0, h=c;
                while(l <= h){
                    int mid = (l+h)/2;
                
                    if(mat[i][mid] == x) return true;
                    else if(mat[i][mid] < x) l = mid+1;
                    else h = mid - 1;
                }
            }
        }
        return false;
    }
};
