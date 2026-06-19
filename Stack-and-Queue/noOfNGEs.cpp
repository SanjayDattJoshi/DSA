//Find number of NGE's 
//BruteForce
vector<int> noOfNGEs(vector<int> arr){
    vector<int> ans;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int cnt = 0;
        bool found = false;
        for(int j = i+1; j<n; j++){
            if(arr[j]>arr[i]){
                cnt++;
                found = true;
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

//Optimal (using monotonic stack)
vector<int> noOfNGEsOp(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    multiset<int> ms;
    
    for(int i = n-1; i >= 0; i--){
        auto it = ms.upper_bound(arr[i]);
        ans[i] = distance(it, ms.end());
        ms.insert(arr[i]);
    }
    return ans;
}
