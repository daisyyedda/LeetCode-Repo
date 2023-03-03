class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> tok;
        for (string i : tokens) {
            int num1, num2;
            if (i == "+" || i == "-" || i == "*" || i == "/") {
                num1 = tok.top();
                tok.pop();
                num2 = tok.top();
                tok.pop();
            }
            if (i == "+") tok.push(num2 + num1);
            else if (i == "-") tok.push(num2 - num1);
            else if (i == "*") tok.push(num2 * num1);
            else if (i == "/") tok.push(num2 / num1);
            else tok.push(stoll(i));
        }
        return tok.top();
    }
};