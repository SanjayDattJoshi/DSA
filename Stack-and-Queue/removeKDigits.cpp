//Remove k digits
string removeKDigits(string s, int k){
    int n = s.length();
    if(k>=n) return "0";
    stack<char> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && k>0 && st.top() - '0' > s[i]-'0'){
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    while(k>0 && !st.empty()) st.pop(), k--;
    if(st.empty()) return "0";

    string res = "";
    while(!st.empty()){
        res = st.top() + res;  
        st.pop();
    }
    
    int i = 0;
    while(i < res.length() && res[i] == '0'){
        i++;
    }
    
    res = res.substr(i);//This creates a substring starting from index 
                        //i to the end of the string.
    return res.empty() ? "0" : res;
}
