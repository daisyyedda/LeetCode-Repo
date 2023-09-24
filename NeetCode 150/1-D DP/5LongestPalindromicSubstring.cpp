class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1, maxStart = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            update(s, i, i, maxLen, maxStart);  // old length
            update(s, i, i + 1, maxLen, maxStart);  // even length
        }
        return s.substr(maxStart, maxLen);
    }
private:
    void update(string s, int start, int end, int& maxLen, int& maxStart) {
        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            // time to extend the palindromic string
            start--;
            end++;
        }
        if (end - start - 1 > maxLen) {
            // time to update max
            maxLen = end - start - 1;
            maxStart = start + 1;
        }
    }
};