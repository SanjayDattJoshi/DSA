//Sum of subarray minimums
//BruteForce
int sumOfSubarrayMinisBr(vector<int>arr){
    int sum = 0;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        int mini = arr[i];
        for(int j = i; j<n; j++){
            mini = min(arr[j], mini);
            sum += mini;
        }
    }
    return sum;
}

//Optimal 
vector<int> findNSE(vector<int>arr){
    int n = arr.size();
    vector<int> nse(n); 
    stack<int> st;
    for(int i = n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

        nse[i] = st.empty()? n : st.top();

        st.push(i);
    }
    return nse;
}
vector<int> findPSE(vector<int>arr){
    int n = arr.size();
    vector<int> pse(n); 
    stack<int> st;
    for(int i = 0; i<n; i++){
        while(!st.empty() && arr[st.top()]>arr[i]) st.pop();

        pse[i] = st.empty()? -1 : st.top();

        st.push(i);
    }
    return pse;
}
long long sumOfSubarrayMinisOp(vector<int>arr){
    long long sum = 0;
    int n = arr.size();
    const int MOD = 1e9 + 7;
    vector<int> NSE = findNSE(arr);
    vector<int> PSE = findPSE(arr);
    for(int i =0; i<n; i++){
        long long left = i - PSE[i];
        long long right = NSE[i] - i;
        sum = (sum+(right*left%MOD)*arr[i]%MOD)%MOD;
    }
    return sum;
}
