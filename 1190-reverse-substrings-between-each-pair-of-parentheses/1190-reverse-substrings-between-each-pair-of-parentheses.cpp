class Solution {
public:
    string reverseParentheses(string s) {
        string st = "";

        for (char c : s) {
            if (c == ')') {
                string temp = "";

                while (!st.empty() && st.back() != '(') {
                    temp += st.back();
                    st.pop_back();
                }
                if (!st.empty() && st.back() == '(') {
                    st.pop_back();
                }

                for (char t : temp) {
                    st.push_back(t);
                }
            }
            else {
                st.push_back(c);
            }
        }
        return st;
    }
};