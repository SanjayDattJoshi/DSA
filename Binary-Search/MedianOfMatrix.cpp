//Median in a Row Wise Sorted Matrix
//BruteForce
int medianRowWiseSorted(vector<vector<int>>& mat){
    if (mat.empty() || mat[0].empty()) {
        return -1;
    }
    int n = mat.size();
    int m = mat[0].size();
    vector<int> arr;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr.push_back(mat[i][j]);
        }
    }
    sort(arr.begin(), arr.end());
    int totalElements = n * m;
    return arr[totalElements / 2];
}

//Optimal
int upperBound(vector<int> &arr, int x, int n){
    int low = 0, high = n-1, ans = n;
    while(low<=high){
        int mid = (low + high) /2;
        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        } 
        else low = mid + 1;
    }
    return ans;
}
int countSmallEqual(vector<vector<int>> &mat, int n, int m, int x){
    int cnt = 0;
    for(int i = 0; i<n; i++){
        cnt += upperBound(mat[i], x, m);
    }
    return cnt;
}
int medianRowWiseSortedOp(vector<vector<int>>& mat){
     if (mat.empty() || mat[0].empty()) {
        return -1;
    }
    int n = mat.size();
    int m = mat[0].size();
    int low = INT_MAX, high = INT_MIN;
    for(int i = 0; i<n; i++){
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m-1]);
    }
    int req = (n * m) / 2;
    while(low<=high){
        int mid = (low+high)/2;
        int smallEqual = countSmallEqual(mat,n,m,mid);
        if(smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
   return low;
}
