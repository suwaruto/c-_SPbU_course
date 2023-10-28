class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        st.push(stoi(*tokens.begin()));
        for (auto it = tokens.begin() + 1; it != tokens.end(); it++)
        {
            if (*it == "+" || *it == "-" || *it == "*" || *it == "/")
            {
                static char operation;
                static int op1 = 0, op2 = 0;
                operation = (*it)[0];
                op1 = st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                switch (operation)
                {
                    case '+':
                        st.push(op2 + op1);
                        break;
                    case '-':
                        st.push(op2 - op1);
                        break;
                    case '*':
                        st.push(op2 * op1);
                        break;
                    case '/':
                        st.push(op2 / op1);
                        break;
                }
            }
            else
                st.push(stoi(*it));
        }
        return st.top();
    }
};
