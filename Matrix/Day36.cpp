/* Spirally traversing a matrix :
You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form. */


class Solution {
  public:
  // write 
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        vector<int> ans;
        int rw = mat.size();
        int c = mat[0].size();
        int top=0,down=rw-1,r=c-1,l=0;
        while(top <= down && l <= r){
            // left to right
            for(int i=l; i<=r; i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            for(int i=top; i<=down; i++){
                ans.push_back(mat[i][r]);
            }
            r--;
            if(top <= down){
                for(int i=r; i>=l; i--){
                    ans.push_back(mat[down][i]);
                }
                down--;
            }
            if(l<=r){
                for(int i=down; i>=top; i--){
                    ans.push_back(mat[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};
