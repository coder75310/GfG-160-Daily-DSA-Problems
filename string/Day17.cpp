/* Non Repeating Character :
Given a string s consisting of lowercase English Letters. 
Return the first non-repeating character in s.
If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1. */


class Solution {
  public:
// Your code here
    char nonRepeatingChar(string &s) {
        int freq[26] = {0};
        
        // First pass: count frequency
        for(char ch : s){
            freq[ch - 'a']++;
        }
        ////////////////////////
        // Second pass: find first non-repeating character
        for(char ch : s){
            if (freq[ch - 'a'] == 1){
                return ch;
            }
        }
        
        // If none found, return '$'
        return '$';
    }
};
