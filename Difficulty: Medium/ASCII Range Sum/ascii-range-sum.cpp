class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        vector<int> res;
        unordered_map<char, pair<int, int>> positions;

        // Record first and last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            if (positions.find(s[i]) == positions.end()) {
                positions[s[i]] = {i, i};
            } else {
                positions[s[i]].second = i;
            }
        }

        // For each character with different first and last occurrence
        for (auto &p : positions) {
            int first = p.second.first;
            int last = p.second.second;

            if (first < last) {
                int sum = 0;
                for (int i = first + 1; i < last; i++) {
                    sum += (int)s[i];
                }
                if (sum > 0) {
                    res.push_back(sum);
                }
            }
        }

        return res;
    }
};