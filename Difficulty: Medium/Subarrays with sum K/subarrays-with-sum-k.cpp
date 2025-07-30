class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0, count = 0;

        // Initialize with sum 0 occurring once to handle subarrays starting at index 0
        prefixSumCount[0] = 1;

        for (int num : arr) {
            prefixSum += num;

            // Check if (prefixSum - k) has occurred before
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - k];
            }

            // Store/update the prefix sum count
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};