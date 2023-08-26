class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int num1, num2;
        for (auto &i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i == "/") {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
            }
            if (i == "+") {
                st.push(num1+num2);
            } else if (i == "-") {
                st.push(num2-num1);
            } else if (i == "*") {
                st.push(num1*num2);
            } else if (i == "/") {
                st.push(num2/num1);
            } else {
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};
