//Postfix to Infix
string postfixToInfix(string s){
    int i = 0;
    int n = s.length();
    stack<string> st;
    while(i<n){
        string newS = "";
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(string(1, s[i])); 
        }

        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string newS = "(" + t2 + string(1, s[i]) + t1 + ")";
            st.push(newS);
        }
        i++;
    }
    return st.top();
}
