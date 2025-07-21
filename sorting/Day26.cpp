/* Non-overlapping Intervals:
Given a 2D array intervals[][], where intervals[i] = [starti, endi]. 
Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note: Two intervals are considered non-overlapping if the end time of one interval is less than or equal to the start time of the next interval.
 */


class Solution {
  public:
  // Your code  
    int minRemoval(vector<vector<int>> &intervals) {
        // code h
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        
        int count = 0;
        int end = intervals[0][1];  // end of first interval
        
        // step 2: Iterate from the second interval
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= end){                  
                // No overlap, update end
                end = intervals[i][1];
            } else {
                //
                count++;
            }
        }
        
        return count;
    }
};







// Method:- 2
// class Solution {
//     public: 
//         int minRemoval(vector<vector<int>> &intervals){
//             // code here
//             sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
//                 return a[1] < b[1];
//             });
            
//             int rev = 0;  // removal overlaping intervals
//             int prev = intervals[0][1];     
            
//             for(int i=1; i<intervals.size(); i++){
//                 if(intervals[i][0] < prev){
//                     rev++;
//                 } else {
//                     prev = intervals[i][1];
//                 }
//             }
            
//             return rev;
//         }
// };
