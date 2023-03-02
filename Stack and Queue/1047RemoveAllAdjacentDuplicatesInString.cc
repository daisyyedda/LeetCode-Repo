// use stack to store the characters that have not been matched yet.
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (!st.empty() && st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }
        string myString;
        while (!st.empty()) {
            myString += st.top();
            st.pop();
        }
        reverse(myString.begin(), myString.end());
        return myString;
    }
};
