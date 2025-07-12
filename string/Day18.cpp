/* Implement Atoi :
Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. 
Refer the below steps to know about atoi() function.

Cases for atoi() conversion:

Skip any leading whitespaces.
Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231. */


class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here  
        int i = 0;
        long result = 0;
        int sign = 1;
        
        // 1. Skip leading whitespaces
        while(s[i] == ' '){
            i++;
        }
        
        // 2. Check for sign
        if(s[i] == '+' || s[i] == '-'){
            if(s[i] == '-') sign = -1;
            i++;
        }
        
        // 3. Convert digits to integer
        while(s[i] >= '0' && s[i] <= '9'){
            int digit = s[i] - '0';
            result = result * 10 + digit;
            
        // 4. Check for Overflow
        if(sign == 1 && result > INT_MAX) return INT_MAX;
        if (sign == -1 && -result < INT_MIN) return INT_MIN;
        
            i++;   
        }
        
        return (int)(sign * result);
    }
};           

