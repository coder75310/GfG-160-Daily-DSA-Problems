/* Find H-Index :
Given an integer array citations[], where citations[i] represents the number of citations for the ith paper, your have to compute the H-index of the researcher.
The H-index is defined as the maximum value H such that the researcher has at least H papers with at least H citations each.
 */


// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
// Your code is here
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for(int i = 0;i < citations.size(); i++){
            if(citations[i] >= i + 1){
                h = i + 1;
            } else {
                break;
            }
        }
        return h;
    }
};
