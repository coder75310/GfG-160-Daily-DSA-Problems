class Solution {
public:
    int countBalanced(vector<string>& arr) {
        unordered_map<int, int> balanceCount;
        balanceCount[0] = 1;  // base case for exact match from beginning

        int balance = 0; // vowel - consonant balance
        int result = 0;

        for (const string& s : arr) {
            int vowels = 0, consonants = 0;

            for (char c : s) {
                if (isVowel(c)) vowels++;
                else consonants++;
            }

            balance += (vowels - consonants);

            // If we have seen this balance before, those subarrays are balanced
            result += balanceCount[balance];
            balanceCount[balance]++;
        }

        return result;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
