class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = int(s.length()), res = 0;
        unordered_map<char, int> hash;
        // store char and index in hash table
        for (int j = 0, i = 0; j < n; j++){
            // the char repeats
            if(hash[s[j]] > 0) {
                i = max(hash[s[j]], i);
            }
            res = max(res, j - i + 1);
            hash[s[j]] = j + 1;
        }
        return res;
    }
};