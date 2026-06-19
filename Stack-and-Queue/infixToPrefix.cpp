// Infix to Prefix
string reverseStr(string str)
{
    int n = str.length();
    int i = 0;
    int j = n-1;
    while(i<j){
        char temp;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}

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

string infixToPrefix(string s)
{
    s = reverseStr(s);
    for(int k = 0; k < s.length(); k++){
        if(s[k] == '(')
            s[k] = ')';
        else if(s[k] == ')')
            s[k] = '(';
    }
    int i = 0;
    stack<char> st;
    string ans = "";
    int n = s.length();

    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
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
            if (s[i] == '^')
            {
                while (!st.empty() &&
                       (priority(s[i]) < priority(st.top())))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() &&
                       (priority(s[i]) < priority(st.top())))
                {
                    ans += st.top();
                    st.pop();
                }
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
    ans = reverseStr(ans);
    return ans;
}
