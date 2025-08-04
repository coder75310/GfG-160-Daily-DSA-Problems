/* Rotate by 90 degree:
Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.  */


class Solution{
    public:
    void rotateMatrix(vector<vector<int>>& mat){
        // code here
        int n=mat.size();
        // Transpose the matrix
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        
        // reverse column
        for(int j=0; j<n; j++){
            for(int i=0, k=n-1; i<k; i++, k--){
                swap(mat[i][j], mat[k][j]);
            }
        }
    }
};








