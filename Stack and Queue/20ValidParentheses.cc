class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
          // push the corresponding right parenthesis into the stack
            if (s[i] == '(') st.push(')');
            else if (s[i]  == '{') st.push('}');
            else if (s[i]  == '[') st.push(']');
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop();
        }
        return st.empty();   
    }
};