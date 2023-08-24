class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxCount = 0, i = 0, j = 0, result = 0;
        while (j < s.size()) {
            count[s[j] - 'A']++;
            // maxCount stores the max number of repeating characters
            maxCount = max(maxCount, count[s[j] - 'A']);
            // need to perform more than k swaps, not feasible, so move the window forward by 1
            if (j - i + 1 - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
            }
            // result stores the max length of the window
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};
