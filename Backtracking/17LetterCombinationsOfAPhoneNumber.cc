class Solution {
private:
        const string letters[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
        };
public:
    vector<string> res;
    void getCombinations(const string& digits, int idx, const string& s) { 
        if (idx == digits.size()) {
            res.emplace_back(s);
            return;
        }
        int digit = digits[idx] - '0';
        string let = letters[digit];
        for (int i = 0; i < let.size(); i++) {
            getCombinations(digits, idx + 1, s + let[i]);  
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return res;
        }
        getCombinations(digits, 0, "");
        return res;

    }
};