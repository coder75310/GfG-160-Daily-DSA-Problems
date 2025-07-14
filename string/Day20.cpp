/* Strings Rotations of Each Other :
You are given two strings s1 and s2, of equal lengths. The task is to check if s2 is a rotated version of the string s1.

Note: A string is a rotation of another if it can be formed by moving characters from the start to the end (or vice versa) without rearranging them. */



class Solution {
  public:
  // write your code here
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        // Step 1: If Lengths are not equal, s2 can't be a rotation of s1
        if(s1.length() != s2.length()) return false;
        
        // step 2: Concatenate s1 with itself
        string temp = s1 + s1;
        
        return temp.find(s2) != string::npos;
    }
};
