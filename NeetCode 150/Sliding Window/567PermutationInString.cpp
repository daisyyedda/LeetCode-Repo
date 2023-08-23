class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int lo = 0;
        vector<int> hash1(26);
        // store the ascii value of each char in s1
        for (int i = 0; i < s1.length(); i++) {
            hash1[s1[i] - 'a']++;
        }
        // slide the window of length s1.length() in s2
        while (lo <= s2.length() - s1.length()) {
            if (isPermutation(s2.substr(lo, s1.length()), hash1)) {
                return true;
            }
            lo++;
        }
        return false;
    }
private:
    bool isPermutation(string s, vector<int> hash1) {
        for (int i = 0; i < s.length(); i++) {
            hash1[s[i]-'a']--;
        }
        // if the string is a permutation of s1, the hash table should be all 0
        for (int i = 0; i < 26; i++) {
            if (hash1[i] != 0) return false;
        }
        return true;
    }
};