class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<int> rowSum(n, 0), colSum(n, 0);
        int total = 0;

        // Compute row and column sums
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
                total += mat[i][j];
            }
        }

        // Get the maximum of any row sum or column sum
        int maxSum = 0;
        for (int i = 0; i < n; ++i) {
            maxSum = max(maxSum, rowSum[i]);
            maxSum = max(maxSum, colSum[i]);
        }

        // Result = total increments needed to bring all rows/cols up to maxSum
        return maxSum * n - total;
    }
};