/* Add Binary Strings :
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.  */
 

// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string result = "";
        
        while(i >= 0 || j >= 0 || carry){
            int bit1 = (i >= 0) ? s1[i--] - '0' : 0;
            int bit2 = (j >= 0) ? s2[j--] - '0' : 0;
            
            int sum = bit1 + bit2 + carry;
            carry = sum / 2;
            result += (sum % 2) + '0';
        }
        
        // Remove leading zeroes (if any)
        while(result.size() > 1 && result.back() == '0'){
            result.pop_back();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
}; 
