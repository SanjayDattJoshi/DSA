// infix to postfix
int priority(char ch)
{
    int pr = -1;
    if (ch == '^')
        pr = 3;
    else if (ch == '*' || ch == '/')
        pr = 2;
    else if (ch == '-' || ch == '+')
        pr = 1;
    return pr;
}
string infixToPostfix(string s)
{
    int i = 0;
    stack<char> st;
    string ans = "";
    int n = s.length();

    while (i < n)
    {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            ans = ans + s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() &&
                   ((s[i] != '^' && priority(s[i]) <= priority(st.top())) ||
                    (s[i] == '^' && priority(s[i]) < priority(st.top()))))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
