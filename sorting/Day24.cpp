/* Overlapping Intervals :
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals. */


class Solution {
  public:
  // write your code he
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        // step 1: Sort intervals based on the starting time
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> merged;
        
        for(const auto& interval : arr){
            // If merged is empty or no overlap,add the interval
            if(merged.empty() || merged.back()[1] < interval[0]){
                merged.push_back(interval);
            } else {
            // Overlap: merge current interval with previous
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};
