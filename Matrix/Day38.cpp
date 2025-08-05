// User function template for C++
class Solution {
  // Your
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int r=0, n=mat.size(), c=mat[0].size()-1;
        while(r<n && c>=0) {
            if(mat[r][c] == x) return true;
            else if(mat[r][c] > x) c--;
            else r++;
        }
        return false;
        
    }
};








