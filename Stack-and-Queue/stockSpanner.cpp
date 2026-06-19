//Stock Span Problem

//BruteForce
vector<int> stockSpannerBrute(vector<int> arr){
    int n = arr.size();
    vector<int> res(n);
    for(int i = 0; i < n; i++){
        int count = 1;
        for(int j = i-1; j>=0; j--){
            if(arr[j]<=arr[i]) count++;
            else break;
        }
        res[i] = count;
    }
    return res;
}

//Optimal
vector<int> stockSpanner(vector<int> arr){
    int n = arr.size();
    vector<int> res(n);
    stack<int> s;
    for(int i = 0; i<n; i++){
        while(!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }
        if(s.empty()){
            res[i] = i + 1;
        }
        else{
            res[i] = i - s.top();
        }
        s.push(i);
    }
    return res;
}
