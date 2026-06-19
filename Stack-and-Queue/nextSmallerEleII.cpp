//Next Greater Element - II
//BruteForce 
vector<int> nextGreaterII(vector<int> arr){
    int n  = arr.size();
    vector<int> ans(n, -1);
    for(int i = 0; i<n; i++){
        for(int j = i+1; j < i+n; j++){
            int idx = j % n;  
            if(arr[idx] > arr[i]){
                ans[i] = arr[idx];
                break;  
            }
        }
    }
    return ans;
}

//Optimal
vector<int> nextGreaterIIOp(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = 2*n-1; i>=0; i--){
        int idx = i%n;
        while(!st.empty() && st.top()<=arr[idx]) st.pop();
        if(i<n){
        if(st.empty()) ans[idx] = -1;
        else ans[idx] = st.top();
        }
        st.push(arr[idx]);
    }
    return ans;
}
