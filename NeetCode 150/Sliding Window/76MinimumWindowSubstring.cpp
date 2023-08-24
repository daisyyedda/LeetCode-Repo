class Solution {
public:
    // runtime O(m+n), sliding window optimized
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        for (int i = 0; i < t.length(); i++) {
            hash[t[i]]++;
        }
        int lo = 0, hi = 0, remaining = t.length();
        int minStart = 0, minWindow = INT_MAX;
        while (hi < s.length()) {
            if (hash[s[hi]] > 0) {
                remaining--;
            }
            hash[s[hi]]--;
            hi++;
            // increment lo to shorten the window
            while (remaining == 0) {
                if (hi - lo < minWindow) {
                    minStart = lo;
                    minWindow = hi - lo;
                }
                // increment as s[lo] is no longer in window
                hash[s[lo]]++;
                // s[lo] was included in string
                if (hash[s[lo]] > 0) {
                    remaining++;
                }
                lo++;
            }
        }
        if (minWindow != INT_MAX) {
            return s.substr(minStart, minWindow);
        }
        return "";
    }
};
