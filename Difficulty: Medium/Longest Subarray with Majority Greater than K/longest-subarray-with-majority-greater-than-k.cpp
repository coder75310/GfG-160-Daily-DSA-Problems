class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        unordered_map<int, int> first_occurrence;
        int prefix = 0;
        int max_len = 0;
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] > k) prefix += 1;
            else prefix -= 1;

            if (prefix > 0) {
                max_len = i + 1;  // from index 0 to i
            } else {
                if (first_occurrence.find(prefix - 1) != first_occurrence.end()) {
                    max_len = max(max_len, i - first_occurrence[prefix - 1]);
                }
            }

            if (first_occurrence.find(prefix) == first_occurrence.end()) {
                first_occurrence[prefix] = i;
            }
        }

        return max_len;
    }
};