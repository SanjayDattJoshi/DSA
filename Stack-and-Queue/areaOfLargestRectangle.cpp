//Area of largest rectangle in histogram

//Bruteforce 
int areaOfLargestRectangleBr(vector<int> arr){
    vector<int> pse = findPSE(arr);
    vector<int> nse = findNSE(arr);
    int n = arr.size();
    int maxi = 0;
    for(int i = 0; i<n; i++){
        maxi = max(maxi, arr[i]*(nse[i]-pse[i]-1));
    }
    return maxi;
}

//Optimal
int areaOfLargestRectangleOp(vector<int> arr){
    int n = arr.size();
    int maxi = 0;
    int element, nse, pse;
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            element = st.top();
            st.pop();
            nse = i;
            pse = st.empty()?-1: st.top();
            maxi = max(arr[element] * (nse - pse - 1), maxi);
        }
        st.push(i);
    }
    while(!st.empty()){
        nse = n;
        element = st.top();
        st.pop();
        pse = st.empty()? -1: st.top();
        maxi = max(arr[element] * (nse - pse - 1), maxi);
    }
    return maxi;
}
