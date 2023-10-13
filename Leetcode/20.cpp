class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (!st.empty() && 
                (st.top() == '{' && *it == '}' ||
                st.top() == '[' && *it == ']' ||
                st.top() == '(' && *it == ')')
            )
            {
                st.pop();
            }
            else
            {
                st.push(*it);
            }
        }
        return st.empty();
    }
};
