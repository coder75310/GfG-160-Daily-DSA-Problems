class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.size();
        int toKeep = n - k;
        vector<char> stack;

        for (char c : s) {
            while (!stack.empty() && k > 0 && stack.back() < c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }

        // Keep only first n - k characters
        string result(stack.begin(), stack.begin() + toKeep);
        return result;
    }
};


