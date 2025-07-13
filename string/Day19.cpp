/* Min Chars to Add for Palindrome :
Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward. */


class Solution {
  public:
      // 
    int minChar(string& s) {
        // Write your code here
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        string temp = s + "#" + rev;
        int n = temp.size();
        vector<int> lps(n,0);
        
        // Build LPS array for the combined string
        for(int i=1; i<n; i++){
            int len = lps[i - 1];
            while(len > 0 && temp[i] != temp[len]){
                len = lps[len - 1];
            }
            if(temp[i] == temp[len]){
                len++;
            }
            lps[i] = len;
        }
        
        // 
        return s.size() - lps[n - 1];
    }
};
