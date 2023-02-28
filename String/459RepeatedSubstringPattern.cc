// match moving window
// Time Complexity: O(n) or O(n^2)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string pair = s + s;
        // remove the first and last chars
        pair.erase(pair.begin()); pair.erase(pair.end() - 1);
        return pair.find(s) != string::npos ? true : false;
    }
};

// KMP
// Time Complexity: O(n)
class Solution {
public:
    // compute the indices of previous occurences of each char, -1 if not found
    void getNext (int* next, const string& s){
        next[0] = -1;
        int j = -1;
        for(int i = 1; i < s.size(); i++){
            while(j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if(s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
            cout << next[i] << endl;
        }
    }
    bool repeatedSubstringPattern (string s) {
        if (s.size() == 0) return false;
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        // check if string length is a multiple of pattern length
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
};