class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        int maxSum = INT_MIN;

        // Iterate over all pairs of rows
        for (int top = 0; top < n; top++) {
            vector<int> temp(m, 0);  // Temporary array to store column sums

            for (int bottom = top; bottom < n; bottom++) {
                // Add the current row to temp (column-wise)
                for (int col = 0; col < m; col++) {
                    temp[col] += mat[bottom][col];
                }

                // Apply Kadane's algorithm on the temp array
                int currSum = temp[0], best = temp[0];
                for (int i = 1; i < m; i++) {
                    currSum = max(temp[i], currSum + temp[i]);
                    best = max(best, currSum);
                }

                maxSum = max(maxSum, best);
            }
        }

        return maxSum;
    }
};
