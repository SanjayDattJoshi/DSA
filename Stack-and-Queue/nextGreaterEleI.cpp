//Next Greater Element 
//BruteForce
vector<int> nextGreater(vector<int> arr){
    vector<int> ans;
    int n = arr.size();
    for(int i=0; i<n; i++){
        bool found = false;
        for(int j = i+1; j<n; j++){
            if(arr[j]>arr[i]){
                ans.push_back(arr[j]);
                found = true;
                break;
            }
        }
        if(!found){
            ans.push_back(-1);
        }
    }
    return ans;
}
//Optimal (using monotonic stack)
vector<int> nextGreaterOp(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = n-1; i>=0; i--){
        while(!st.empty() && st.top()<=arr[i]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}
