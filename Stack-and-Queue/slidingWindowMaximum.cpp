// Sliding Window Maximum

// Bruteforce
vector<int> slidingWindowMaxiBr(vector<int> arr, int k)
{
    vector<int> maxi;
    int n = arr.size();
    int m;
    for (int i = 0; i <= n - k; i++)
    {
        m = arr[i];
        for (int j = i; j < i + k; j++)
        {
            m = max(m, arr[j]);
        }
        maxi.push_back(m);
    }
    return maxi;
}

// Optimal
vector<int> slidingWindowMaxiOp(vector<int> arr, int k){
    vector<int> maxi;
    int n = arr.size();
    deque<int> dq;  // Stores indices in decreasing order of values
    
    for(int i = 0; i <= n - 1; i++){
        // Remove indices outside current window
        if(!dq.empty() && dq.front() <= i-k) 
            dq.pop_front();
        
        // Remove smaller elements (they can't be max)
        while(!dq.empty() && arr[dq.back()] <= arr[i]) 
            dq.pop_back();
        
        // Add current index
        dq.push_back(i);
        
        // Add max to result (window is complete)
        if(i >= k-1) 
            maxi.push_back(arr[dq.front()]);
    }
    return maxi;
}
