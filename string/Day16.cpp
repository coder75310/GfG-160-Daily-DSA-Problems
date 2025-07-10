/* Anagram :
Given two non-empty strings s1 and s2, consisting only of lowercase English letters, determine whether they are anagrams of each other or not. 
Two strings are considered anagrams if they contain the same characters with exactly the same frequencies, regardless of their order. */


class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        if(s1.length() != s2.length()) 
            return false;
            
        int freq[26] = {0};
        
        // Count frequency for s1
        for(char c : s1){
            freq[c - 'a']++;
        }
        
        // Subtract frequency for s2
        for(char c : s2){
            freq[c - 'a']--;
        }
        
        // Check if all counts are 0
        for(int i=0; i<26; ++i){
            if(freq[i] != 0)
                return false;
        }
            
            return true;
        }
};
