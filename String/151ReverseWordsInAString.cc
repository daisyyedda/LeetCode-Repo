class Solution {
public:
    void reverse(string& s, int start, int end){ 
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    // use two pointers (similar to #27)
    void removeExtraSpace(string &s) {
        int slow = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') { 
                // make sure there is only one whitespace b/w words
                if (slow != 0) s[slow++] = ' '; 
                // adjust
                while (i < s.size() && s[i] != ' ') { 
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        // remove all extra whitespaces
        removeExtraSpace(s);
        // reverse entire string
        reverse(s, 0, s.size() - 1);
        // reverse each word
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1; 
            }
        }
        return s;
    }
};
