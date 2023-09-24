class Solution {
public:
    int countSubstrings(string s) {
        int total = 1;
        for (int i = 0; i < s.length() - 1; i++) {
            update(s, i, i, total);  // old length
            update(s, i, i + 1, total);  // even length
        }
        return total;
    }
private:
    void update(string s, int start, int end, int& count) {
        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            // time to extend the palindromic string
            count++;
            start--;
            end++;
        }
    }
};