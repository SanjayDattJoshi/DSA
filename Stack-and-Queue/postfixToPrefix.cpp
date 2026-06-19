//Postfix to Prefix
string postfixToPrefix(string s){
    stack<string> st;
    int n = s.length();
    for(int i = 0; i<n ; i++){
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(string(1, s[i])); 
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(string(1, s[i]) + t2 + t1); 
        }
    }
    return st.top();
}
